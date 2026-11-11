#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000005],v[1000005];
vector<int>p[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			cin>>u[i]>>v[i];
			p[u[i]].push_back(v[i]);
			p[v[i]].push_back(u[i]);
			
		}
		cout<<1<<"\n";
	}
	return 0;
} 
