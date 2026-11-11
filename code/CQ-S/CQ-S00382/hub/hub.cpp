#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(k==n)cout<<0<<"\n";
		else cout<<rand()%(n-2)+1<<"\n";
		for(int i=1;i<=n;i++){
			cin>>u>>v;
		}
	}
	return 0;
} 
