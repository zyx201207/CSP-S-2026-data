#include<bits/stdc++.h>
using namespace std;
const int N = 4000;
long long opt,qt,n,m;
vector<int> g[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>opt>>qt;
	while(qt--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		cout<<n-1<<endl;
	}
	return 0;
}
/*


*/
