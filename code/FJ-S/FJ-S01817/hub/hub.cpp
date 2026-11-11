#include <bits/stdc++.h>
using namespace std;
int T,n,m,x,y;
vector<int> v[10000001];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
//		for(int i=1;i<n;i++)
//			v[x].clear();
		for(int i=1;i<n;i++){
			cin>>x>>y;
//			v[x].push_back(y);
//			v[y].push_back(x);
		}
		n=n-1-m*2;
		cout<<(n-1)/3+1<<"\n";
	}
	return 0;
}
