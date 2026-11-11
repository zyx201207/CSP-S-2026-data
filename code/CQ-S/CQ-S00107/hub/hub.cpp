#include<bits/stdc++.h>
using namespace std;
struct ky{
	vector<int> b;
};
void bfs(int n,ky a[],int k){
	if(a[n].b.size()>=k){
		cout << k-1 << endl;
		return;
	}
	for(int i=0;i < a[n].b.size();i++){
		bfs(a[n].b[i],a,k);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >>t;
	while(t--){
		int n,k;
		cin >> n >> k;
		ky a[n+1];
		for(int i=0;i < n-1;i++){
			int u,v;
			cin >> u,v;
			a[u].b.push_back(v);
			a[v].b.push_back(u);
		}
		bfs(1,a,k);
	}
	return 0;
}
