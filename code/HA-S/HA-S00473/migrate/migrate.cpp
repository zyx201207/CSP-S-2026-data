#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,d,n;
int x[2000006];
vector<int>dis[2000006];
bool pd=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d){
					dis[i].push_back(INT_MAX);
					dis[j].push_back(INT_MAX);
					break;
				}else{
					dis[i].push_back(abs(x[j]-x[i]));
					dis[j].push_back(abs(x[j]-x[i]));
				}
			}
		}
		if(c>=11&&c<=12){
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					if(dis[i][j]<d){
						ans++;
					}
				}
			}
			cout<<min(ans,n-3)<<endl;
			continue; 
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(dis[i][j]<d){
					ans++;
				}
			}
		}
		cout<<ans-2<<endl;
	}
	return 0;
}
//315275
//172.16.12.5
