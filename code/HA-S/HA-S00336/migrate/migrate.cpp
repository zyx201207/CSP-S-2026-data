#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000010;
int c,t,n,d,a[N],f[N][5],nxt[N],s[N],g[N][5];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n+1;i++) f[i][0]=f[i][1]=f[i][2]=f[i][3]=nxt[i]=g[i][0]=g[i][1]=g[i][2]=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) nxt[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;//,cout<<nxt[i]<<' ';
//		cout<<'\n';
		for(int i=n;i>=1;i--){
			int x=i-1;
			if(i>=2) g[i][2]=1+nxt[i]-nxt[x]+max(0ll,g[nxt[i]][min(2ll,nxt[i]-nxt[x])]-1);
			if(i>=1) g[i][1]=1+nxt[i]-i+max(0ll,g[nxt[i]][min(2ll,nxt[i]-i)]-1);
		}
		int ans=0;
		for(int i=n;i>=1;i--){
			int x=i-2,y=i-1;
			if(i>=3){
				if(nxt[i]==nxt[y]) f[i][3]=nxt[y]-nxt[x]+(nxt[y]>=nxt[nxt[x]]?max(0ll,g[nxt[y]][min(2ll,nxt[y]-nxt[x])]-1):0);
				else f[i][3]=nxt[y]-nxt[x]+(nxt[i]>=nxt[nxt[y]]?f[nxt[i]][min(3ll,nxt[i]-nxt[y])]:0);
			}
			if(i>=2){
				if(nxt[i]==nxt[y]) f[i][2]=max(0ll,nxt[y]-i)+max(0ll,g[nxt[y]][max(0ll,min(2ll,nxt[y]-i))]-1);
				else f[i][2]=max(0ll,nxt[y]-i)+(nxt[i]>=nxt[nxt[y]]||nxt[y]-i<=0?f[nxt[i]][min(3ll,nxt[i]-nxt[y])]:0);
			}
			if(i>=1) f[i][1]=f[nxt[i]][min(3ll,nxt[i]-i)];
			ans+=f[i][1];
//			if(f[i][1]>=1000) cout<<i<<' '<<f[i][1]<<' '<<f[i][2]<<' '<<f[i][3]<<' '<<nxt[i]<<' '<<g[i][1]<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}

