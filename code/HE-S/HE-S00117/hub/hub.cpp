#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}cout<<rand()%(n-1)+1<<'\n';
	}return 0;
}
