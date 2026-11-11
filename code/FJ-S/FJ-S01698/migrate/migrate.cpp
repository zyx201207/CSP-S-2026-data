#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d;
int x[N],lj[15][15],ss[15][15];
int ff[5005][5005];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		if(n<=9){
			memset(ss,0x3f,sizeof(ss));
			memset(lj,0,sizeof(lj));
			for(int i=0;i<(1<<n);++i){
				bool f=1;
				int bg=-1,lt=-1,sum=0;
				for(int j=0;j<n;++j){
					if(!f) break;
					if(i&(1<<j)){
						if(lt!=-1){
							if(x[j+1]-x[lt]>d){
								f=0;
								break;
							}
						}
						lt=j+1;
						if(bg==-1) bg=j+1;
					}
				}
				if(f){
					if(ss[bg][lt]>sum){
						ss[bg][lt]=sum;
						lj[bg][lt]=1;
					}
					else if(ss[bg][lt]==sum) ++lj[bg][lt];
				}
			}
			int ans=0;
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					if(lj[i][j]==3) ++ans;
//					cout<<lj[i][j]<<" ";
				}
//				cout<<"\n";
			}
			cout<<ans<<"\n";
		}
		else{
			memset(ff,0x3f,sizeof(ff));
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					if(x[j]-x[i]<=d) ff[i][j]=1;
				}
			}
			for(int k=1;k<=n;++k){
				for(int i=1;i<=n;++i){
					for(int j=1;j<=n;++j){
						if(ff[i][j]>ff[i][k]+ff[k][j]){
							ff[i][j]=ff[i][k]+ff[k][j];
							lj[i][j]=1;
						}
						else if(ff[i][j]==ff[i][k]+ff[k][j]) ++lj[i][j];
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					if(lj[i][j]==3) ++ans;
//					cout<<lj[i][j]<<" ";
				}
//				cout<<"\n";
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6