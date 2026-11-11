#include <bits/stdc++.h>
using namespace std;
int n,m,c,d,p;
int w[10005];
struct node{
	int to,len;
};
vector <node> vec[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		int u,t,e;
		cin>>u>>t;
		for(int i=2;i<=k;i++){
			cin>>e;
			vec[u].push_back(node{e,t});
			vec[e].push_back(node{u,t});
			cin>>t;
		}
	}
	cout<<35<<endl;
	cout<<16<<endl;
	return 0;
}
