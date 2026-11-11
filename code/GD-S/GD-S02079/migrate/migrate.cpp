#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000008],ans;
vector<int> g[2000008];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[k]-a[j]<=d){
					g[k].push_back(j);
				}
			}
		}for(int j=1;j<=n;j++){
			if(g[j].size() and g[j].size()==2)
				ans++;
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
