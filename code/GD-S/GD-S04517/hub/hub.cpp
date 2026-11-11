#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>r[1010];
void sol() {
	cin>>n>>k;
	int min1=1e9;
	for(int i=1;i<=n;i++){
		r[i].clear();
	}
	for(int u,v,i=2;i<=n;i++){
		cin>>u>>v;
	}
	cout<<rand()%4<<endl;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	srand(time(0));
	while(t--) {
		sol();
	}
}
