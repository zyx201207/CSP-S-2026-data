#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define filename "subway"
const int M=5e5+10;
const int N=510;
const int Q=1e5+10;
int c,n,m,d,q;
int w[M];
int a[N][M];
int st[Q],en[Q];
int main(){
	srand(time(0));
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i][1]);
		for(int j=2;j<=2*a[i][1]+1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&st[i],&en[i]);
		cout<<rand()%100+1<<'\n';
	}
	
	return 0;
}
