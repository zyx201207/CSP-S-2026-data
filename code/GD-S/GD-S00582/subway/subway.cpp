#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[30080],a[501][25001],k[50001],t[501][25001];
int p[30081];
//struct node{
//	int x;
//};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		queue<int> q;
		q.push(x);
		memset(p,0,sizeof(p));
	}
	
	
}
