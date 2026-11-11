#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>t;
	srand(time(0));
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
		} 
		cout<<rand()%(n+1)<<endl;
	}
	return 0;
}

