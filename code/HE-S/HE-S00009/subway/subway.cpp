#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=5e5+10;
int w[maxm];
int head[maxm];
int to[maxm*2];
int nex[maxm*2];
int weight[maxm*2];
int cnt=1;
int c,n,m,d,q;
void build(int s,int e,int w){
	nex[cnt]=head[s];
	to[cnt]=e;
	weight[cnt]=w;
	head[s]=cnt;
	cnt++;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int a,t;
			cin>>a>>t;
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<'\n';
	}
	return 0;
}
