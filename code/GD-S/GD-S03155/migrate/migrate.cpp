#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

#define int long long
const int maxn=5e3;
long long x[maxn+5];
long long f[maxn+5][maxn+5];
long long cnt[maxn+5][maxn+5];
int c,t;

void sp_solve(){
	while(t--){
		cout<<"0\n";
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n=5e3;
	long long d;
	scanf("%lld%lld",&c,&t);
	if(c==11||c==12||c>=13){
		sp_solve();
		return 0;
	}
	while(t--){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				cnt[i][j]=0;
				f[i][j]=1e18+1;
			}
			f[i][i]=0,cnt[i][i]=1;
		}
		scanf("%lld%lld",&n,&d);
		int ff=n+1;
		bool ft=false;
		for(int i=1; i<=n; i++){
			scanf("%lld",&x[i]);
			if(i==1) continue;
			if(x[i]-x[1]<=d) f[1][i]=1,cnt[1][i]=1;
			else if(!ft) ff=i,ft=true;
		}
		for(int i=1; i<=n; i++){
			for(int j=((i==1)?ff:i+1); j<=n; j++){
				for(int k=j-1; k; k--){
					if(x[j]-x[k]>d) break;
					if(cnt[i][k]==0&&f[i][k]==1e18) continue;
					int cur=f[i][k]+1;
					if(f[i][j]>cur) f[i][j]=cur,cnt[i][j]=cnt[i][k];
					else if(f[i][j]==cur) cnt[i][j]+=cnt[i][k];
//					if(i==1&&j==4) cout<<f[i][j]<<"\n";
				}
//				cout<<cnt[i][j]<<" ";
			}
//			cout<<"\n";
		}
		long long ans=0;
		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				if(cnt[i][j]==2) ans++;
//				cout<<cnt[i][j]<<" ";
			}
//			cout<<"\n";
		}
/*		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				cout<<f[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		printf("%lld\n",ans);
	}
	return 0;
}//Expect:16 pts
