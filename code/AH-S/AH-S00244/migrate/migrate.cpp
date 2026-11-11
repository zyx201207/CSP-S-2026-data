#include<bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
#define PLI pair<LL,int>
using namespace std;
int cid,T;
namespace sub1{
	const int N=310;
	int n,f[N][N],g[N][N];
	bool st[N][N];
	LL d,x[N];
	void solve(){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					st[i][j]=false;
					f[i][j]=0x3f3f3f3f;
					g[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++) f[i][i]=0,g[i][i]=1;
			for(int len=2;len<=n;len++){
				for(int l=1;l+len-1<=n;l++){
					int r=l+len-1;
					for(int k=l;k<r;k++){
						if(x[r]-x[k]>d) continue;
						if(f[l][r]>f[l][k]+1){
							f[l][r]=f[l][k]+1;
							g[l][r]=g[l][k];
							st[l][r]=st[l][k];
						}else if(f[l][r]==f[l][k]+1){
							if(st[l][k]) st[l][r]=true;
							else{
								g[l][r]+=g[l][k];
								if(g[l][r]>2) st[l][r]=true;
							}
						}
					}
				}
			}
			int res=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					//cout<<i<<" "<<j<<" "<<st[i][j]<<" "<<f[i][j]<<"\n";
					res+=(g[i][j]==2&&!st[i][j]);
					//if(g[i][j]==2&&!st[i][j]) cout<<i<<" "<<j<<"\n";
				}
			}
			cout<<res<<"\n";
		}
	}
}
namespace sub2{
	const int N=2e6+10;
	int n;
	LL d,x[N];
	void solve(){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			LL gongcha=x[2]-x[1];
			if(gongcha>=d){
				cout<<"0\n";
				continue;
			}
			LL max_step=d/gongcha;
			LL len=max_step+max_step-1;
			int res=0;
			for(int i=1;i<=n;i++){
				if(i+len<=n) res++;
			}
			cout<<res<<"\n";
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>cid>>T;
	if(cid>=0&&cid<=6) sub1::solve();
	else if(cid==11||cid==12) sub2::solve();
	return 0;
}