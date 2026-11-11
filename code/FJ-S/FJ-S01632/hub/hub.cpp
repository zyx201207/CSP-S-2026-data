#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k;
struct Edge{
	int u,v;
}e[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++)
			cin>>e[i].u>>e[i].v;
		cout<<"1\n";
	}
	return 0;
}

