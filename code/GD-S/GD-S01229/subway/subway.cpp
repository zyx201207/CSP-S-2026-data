#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5,M=5e5+5;
int ccc,n,m,d,q,n2;
ll w[N],a[M],t[M],b[N][N];
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&ccc,&n,&m,&d,&q),memset(b,0x3f,sizeof b),n2=m;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k>>a[1]>>t[1],n2++,b[a[1]][n2]=b[n2][a[1]]=t[1];
		for(int j=2;j<=k;j++) cin>>a[j]>>t[j],n2++,b[n2-1][n2]=b[n2][n2-1]=0,b[a[j]][n2]=b[n2][a[j]]=t[j];
	}
	for(int k=1;k<=n2;k++)
		for(int i=1;i<=n2;i++)
			for(int j=1;j<=n2;j++) b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y),printf("%lld\n",b[x][y]+w[x]+w[y]);
	}
	return 0;
}
