#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		vector<int>vec[1005];
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		
	}
	return 0;
}
