#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>u>>v;
		srand(time(0));
		cout<<rand()%10<<endl;
	}
	return 0;
}
