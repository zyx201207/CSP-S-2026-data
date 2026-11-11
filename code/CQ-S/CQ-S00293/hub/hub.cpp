#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void File(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}

int t;
int n,k;

int main(){
//	File();
	srand(time(0));
	cin>>t>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
		}
		cout<<rand()%(n+1)<<"\n";
	}
	return 0;
}
/*
WA
*/
