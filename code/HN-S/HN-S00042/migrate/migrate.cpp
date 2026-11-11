#include<bits/stdc++.h> 
using namespace std;
int c,t,d,n,w[100005],dis[10005][10005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d; 
		for(int i=1;i<=n;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=j-i;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<=j;k++){
//					cout<<i<<' '<<k<<' '<<j<<'\n';
					if(dis[i][j]>dis[i][k]+dis[k][j]&&dis[i][k]<d&&dis[k][j]<d){
						dis[i][j]=dis[i][k]+dis[k][j];
//						cout<<i<<' '<<k<<' '<<j<<'\n';
					}
					else {ans++;break;}
				}
				
			}
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}
/*
¹Ø×¢Hamster_EmperorÐ»Ð»ß÷ 
*/
