#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
struct node{int f,a;}b[N];
int n,m,a[N],vt[M];
long long c[N],z[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	b[n]={0,a[n]},vt[a[n]]=n;
	for(int i=n-1;i>=1;i--){
		if(vt[a[i]]){
			b[i]={vt[a[i]],0};
		}else{
			b[i]={i+1,a[i]};
		}vt[a[i]]=i;
	}
	for(int i=1;i<=n;i++)c[i]=1;
	for(int i=1;i<=n;i++){
		c[b[i].f]+=c[i];
		if(b[i].a)z[b[i].a]+=c[i];
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",z[i]);
	return 0;
}
