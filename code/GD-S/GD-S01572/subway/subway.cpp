#include<bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int w[100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			v[a].push_back(t);
		}
	}
	int x,y;
	scanf("%d%d",&x,&y);
	int ans=w[x]+w[y];
	
	return 0;
} 
