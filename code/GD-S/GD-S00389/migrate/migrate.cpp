#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,nxt[N];
long long x[N],a[N],b[N],ans;
bool chk(int j,int i){
	int u=x[i]-x[i-1],v=x[i+1]-x[i];
	int p=x[i]-x[i-2],q=x[i+2]-x[i];
	int f=(x[i]-x[j]+v<=d&&(x[i]-x[j]+q>d||nxt[i]-i<2));
	int g=(x[nxt[i]]-x[i]+u<=d&&(x[nxt[i]]-x[i]+p>d||i-j<2));
	return (f^g);
}
void solve2(){
	for(int i=0;i<=n*2;i++)a[i]=b[i]=nxt[i]=0;
	int j=0;
	for(int i=1;i<=n;i++){
		while(j<n&&x[j+1]-x[i]<=d)j++;
		nxt[i]=j;
	}
	for(int i=n;i>=1;i--){
		int nx=nxt[i];
		int u=x[nxt[i]]-x[nxt[i]-1];
		int y=nxt[nx];
		for(int j=20;j>=0;j--){
			int ny=y-(1<<j);
			if(ny<=nx)continue;
			if(x[ny]-x[nx]>d-u)y=ny;
		}
		bool p=(x[nxt[i]]-x[i]+x[nxt[i]+1]-x[nxt[i]]>d);
		bool q=(x[nxt[nxt[i]]]-x[nxt[i]]+x[nxt[i]]-x[nxt[i]-1]>d);
		a[i]=(p&&q?a[nxt[i]]:0)+nxt[nx]-y+1;
		if(nxt[nxt[i]]==nxt[i])a[i]=0;
	}
	for(int i=1;i<=n;i++)b[nxt[i]]++;
	for(int i=1;i<=n;i++)b[nxt[i]]+=b[i];
	for(int i=1;nxt[nxt[i]]!=nxt[i];i++){
		int r=nxt[nxt[i]],l=nxt[nxt[i]];
		int o=x[nxt[i]]-x[nxt[i]-1];
		int w=x[nxt[i]]-x[nxt[i]-2];
		for(int j=20;j>=0;j--){
			int nl=(l-(1<<j));
			int nr=(r-(1<<j));
			if(nl>=nxt[i])if(x[nl]-x[nxt[i]]+w>d)l=nl;
			if(nr>=nxt[i])if(x[nr]-x[nxt[i]]+o>d)r=nr;
		}
		if(x[r]-x[nxt[i]]+o>d)r--;
		int g=(l>nxt[i]&&r>nxt[i]&&x[r]-x[nxt[i]]+o<=d&&x[l]-x[nxt[i]]+w>d&&x[r]-x[nxt[i]]<=d&&x[l]-x[nxt[i]]<=d?(r-l+1):0);
		int f=(chk(i,nxt[i])?a[nxt[i]]:0);
		int h=(x[nxt[i]]-x[i]+x[nxt[i]+1]-x[nxt[i]]<=d&&x[nxt[i]]-x[i]+x[nxt[i]+2]-x[nxt[i]]>d?nxt[nxt[i]]-nxt[i]-1-g:0);
		ans+=b[nxt[i]]*(g+f+(h>0?h:0));
	}
	
}
void solve(){
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	solve2();
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}

