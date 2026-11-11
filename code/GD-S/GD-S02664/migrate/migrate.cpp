#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int t;
ll n,d,a[N],dis[5010][5010],c,ansa;
ll ans[5010][5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ansa=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<=i;j++){
				dis[j][i]=N+10;
				ans[j][i]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d){
					break;
				}
				dis[i][j]=1;
				ans[i][j]=1;
				for(int k=1;k<=i;k++){
					if(dis[k][i]+dis[i][j]<dis[k][j]){
						if(ans[k][j]==2)ansa--;
						ans[k][j]=1;
						dis[k][j]=dis[k][i]+dis[i][j];
					}else if(dis[k][i]+dis[i][j]==dis[k][j]){
						if(ans[k][j]==2)ansa--;
						ans[k][j]++;
						if(ans[k][j]==2)ansa++;
					}
				}
			}
		}
		cout<<ansa<<endl;
	}
	return 0;
}
