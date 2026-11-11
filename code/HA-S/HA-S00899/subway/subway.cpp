#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N];
int a[N][N],t[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++){
		scanf("%d",&w[i]);
	}
	int k=0;
	while(n--){
		scanf("%d",&k);
		int i=1;
		for(int j=1;j<=k;j++){
			scanf("%d %d",&a[i][j],&t[i][j]);
		}
		i++;
	}
	while(q--){
		int x, y;
		scanf("%d %d",&x,&y);
	}
	int time=0;
	
	while(q--){
		printf("%d",time);
	}
	return 0;
}
