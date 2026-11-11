#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int l,r,n,m,d,p,w[N],k[N];
struct node{
	int idx,data;
}t[N];
vector<node>e[N];
vector<int>g[N];
bool cmp(node x,node y){
	return x.data<y.data;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			node f;
			cin>>f.idx>>f.data;
			e[i].push_back(f);
			t[f.idx]={f.idx,f.data};
		}
	}
	return 0;
}

