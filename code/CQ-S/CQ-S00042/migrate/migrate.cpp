#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace zzy{
	const int maxn=2e6+10;
	int cid,T,n;ll d;
	ll ans;
	ll a[maxn];
	int nxt[maxn];
	int f[maxn][2];
	int main(){
		cin>>cid>>T;
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=1;i<=n;i++)f[i][0]=f[i][1]=0;
			int p=n;
			for(int i=n;i>=1;i--){
				while(a[p]-a[i]>d)p--;
				nxt[i]=p;
			}
//			for(int i=1;i<=n;i++)cerr<<nxt[i]<<' ';
//			cerr<<'\n';
			nxt[0]=0;
			ll ans=0;
			for(int i=n;i>=1;i--){
				int dlt=0;
				if(nxt[i]!=i){
					int p=nxt[i];
					if(nxt[p-1]>p){
						dlt=nxt[p-1]-max(p,nxt[p-2]);
						ans+=dlt;
						if(nxt[i-1]>=p-1)dlt=0;
					}
				}
				ans+=f[nxt[i]][1];
				if(nxt[i]!=nxt[i-1]){
					f[i][0]+=f[nxt[i]][0];
					f[i][1]+=f[nxt[i]][1];
					f[i][0]+=nxt[i]-max(i,nxt[i-1]);
//					if(i!=1&&nxt[i-1]!=nxt[i-2]&&nxt[i-1]>=i)f[i][1]+=nxt[i-1]-max(i,nxt[i-2]);
					f[i][1]+=dlt;
				}else if(nxt[i-1]!=nxt[i-2]){
					f[i][1]+=f[nxt[i]][0];
//					f[i][1]+=nxt[i-1]-max(i,nxt[i-2]);
//					f[i][1]+=dlt;
				}
			}
			cout<<ans<<'\n';
		}

		return 0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	zzy::main();
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 13 16 19
*/

