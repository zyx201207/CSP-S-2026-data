#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int n,nxt[N],pre[N];
ll d;
ll a[N],f[N],g[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int r=1;
		for(int i=1;i<=n;i++){
			while(r<n && a[r+1]-a[i]<=d) r++;
			nxt[i]=r;
		}
		int l=n;
		for(int i=n;i>=1;i--){
			while(l>1 && a[i]-a[l-1]<=d) l--;
			pre[i]=l;
		}
		ll ans=0;
		for(int i=n-1;i>=1;i--){
			f[i]=0;
			g[i]=1;
			if(nxt[i]==i) continue;
			for(int j=i+1;j<=n;j++){
				
				int p=max(pre[j],i);
				f[j]=f[p]+1;
				g[j]=g[p];
				if(g[p]>2) continue;
				if(p<j-1 && f[p+1]==f[j]-1) g[j]++;
				if(p<j-2 && f[p+2]==f[j]-1) g[j]++;
				//cout<<g[j]<<' '<<i<<' '<<j<<'\n';
				if(g[j]==2) ans++;
				if(nxt[j]==j) break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
