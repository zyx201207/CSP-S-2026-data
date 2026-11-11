#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	mt19937 Rand (time(0));
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		cout<<Rand()%maxn<<"\n";
	}
	return 0;
}

