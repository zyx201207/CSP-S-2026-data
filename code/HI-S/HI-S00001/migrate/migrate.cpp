#include<bits/stdc++.h>
using namespace std;
int n,d,x[1000010],dis[1010][1010],ans[1010][1010];
vector<int>g[1000010];
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&abs(x[i]-x[j])<=d){
				g[i].push_back(j);
				g[j].push_back(i); 
			}
		}
	}
	
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ans[i][j]==2) res++;
		}
	}
	cout<res<<"\n";
	return 0;
}

