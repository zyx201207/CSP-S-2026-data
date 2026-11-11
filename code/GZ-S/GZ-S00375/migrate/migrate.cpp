//贵阳市南明区李端棻中学刘沛羽GZ-S00375 
#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
struct{
	int to;
	long long w;
};
vector<Edge> g[999999],
long long a[100000],dis[100][100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t>>n>>d;
	for(int i=0;i<n;i++){
		int a;
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(abs(a[i]-a[j])<d){
				g[i].push_back({j,abs(a[i]-a[j])});
				g[j].push_back({i,abs(a[i]-a[j])});
				dis[i][j]=abs(a[i]-a[j]);
			}
			else if(i-j==1){
				g[j].push_back({i,1e18});
				dis[i][j]=5201314520;
			}
			else if(j-i==1){
				g[i].push_back({j,1e18});
				dis[i][j]=5201314520;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(i!=j&&i!=k&&j!=k){
					
				}
			}
		}
	}
	return 0;
}

