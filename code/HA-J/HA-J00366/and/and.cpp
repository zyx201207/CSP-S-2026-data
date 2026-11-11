#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#define pown 2147483647
using namespace std;
int n,m;
int maxn,sum;
struct node{
	int a,s;
}nu[200010];
bool cmp(node x,node y){
	return x.s>y.s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&nu[i].a);
		maxn=max(maxn,nu[i].a);
		nu[i].s=nu[i].a&pown;
	}
	if(m==1){
		printf("%d",maxn);
		return 0;
	}
	else if(m==2){
		maxn=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,nu[i].a&nu[j].a);
			}
		}
		printf("%d",maxn);
		return 0;
	}
	else if(m==n){
		maxn=nu[1].a;
		for(int i=1;i<=n;i++){
			maxn=maxn&nu[i].a;
		}
		printf("%d",maxn);
		return 0;
	}
	sort(nu+1,nu+1+n,cmp);
	int ans=nu[1].s;
	for(int i=1;i<=m;i++){
		ans&=nu[i].s;
	}
	printf("%d",ans);
	return 0;
}
//2^31-1=2147483647
