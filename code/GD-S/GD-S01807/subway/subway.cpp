#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=500,MAXM=1e5;

int c,n,m,d,q;
int w[MAXM+5]; //walk to zhanting.
int a[MAXN+5][MAXM+5]; //line 's station
int t[MAXN+5][MAXM+5]; // zhanting to line i's zhantai
int sz[MAXN+5]; // num of station

struct Node{
	int nd,l;
};
vector<Node> V[MAXM+5];


signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>sz[i];
		for(int j=1;j<=sz[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		
	}
	
	return 0;
}
