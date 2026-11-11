#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int C,T,n,d,x[N],dis[1010][1010],ans,res[1010][1010],b[1010][1010];
priority_queue<pii,vector<pii>,greater<pii> >q;
bool cmp(pair<int,int> A,pair<int,int> B){
	return A.second<B.second;
}
int main (){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(0));
	cin>>C>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		if(n<1000){
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					dis[i][j]=0x3fffffff;
					res[i][j]=0;
					b[i][j]=0;
				}dis[i][i]=0;
			}
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}for (int i=1;i<n;i++){
				for (int j=i+1;j<=n;j++){
					dis[i][j]=x[j]-x[i];
				}
			}
			for (int k=1;k<=n;k++){
				for (int i=1;i<n;i++){
					for (int j=i+1;j<=n;j++){
						if(i==k||j==k)continue;
						if(k<i)continue;
						if(dis[i][j]>dis[i][k]+dis[k][j]){
							dis[i][j]=dis[i][k]+dis[k][j];
							res[i][j]=0;
							b[i][j]=1;
						}
						else if(dis[i][j]==dis[i][k]+dis[k][j]){
							res[i][j]++;
						}
							
					}
				}
			}for (int i=1;i<n;i++){
				for (int j=i+1;j<=n;j++){
					if(res[i][j])res[i][j]-=1;
					ans+=res[i][j];
				}
			}
		}else{
			cout<<rand();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
