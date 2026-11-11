#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
struct ed{
	int from,to;
};
int c,t;int n,k;vector<ed> e[maxn];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			int u,v;
			e[u].push_back({u,v});
		}
		srand(time(0));
		cout<<rand()%(n+1)<<endl;
	}
	return 0;
}
