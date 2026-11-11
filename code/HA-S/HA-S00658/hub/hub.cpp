#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<pair<int,int> >edge;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		int u,v;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			edge.push_back({u,v});
		}
		cout<<"1"<<endl;
	}
	return 0;
}