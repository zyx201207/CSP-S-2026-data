#include<bits/stdc++.h>
using namespace std;
int  c,t,n,d,dis[500005],a[500005],vis[500005];
vector<pair<int,int> >mp[500005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}	
		cout<<(n+1)/d-1<<endl;
	} 
	
	return 0;
}
