#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v;
	int to;
};
int c,n,m,d,q;
long long w[500005],a[500005],t[500005];
vector<node> g[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>t[j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
	return 0;
}
