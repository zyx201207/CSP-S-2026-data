#include<bits/stdc++.h>
using namespace std;
int n,m;
int u,c;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=y;i++){
		cin>>n>>m;
		for(int j=1;j<=n-1;j++){
			cin>>u>>c;
		}
	}
	cout<<u<<'\n'<<c;
	return 0;
}
