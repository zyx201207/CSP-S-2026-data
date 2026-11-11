#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	long long num=0,n0=0,n1=0;	
}a[200010];
bool cmp(node a,node b){
	if(a.n1+a.n0==b.n1+b.n0)
	return a.num>b.num;
	else
	return a.n1+a.n0>b.n1+b.n0;
}
void ejz(int x,int i){
	a[i].num=x;
	while(x){
		if(x&1)a[i].n1++;
		else a[i].n0 ++;
		x>>=1;		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		long long x;
		scanf("%lld",&x);
		ejz(x,i);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=m;i++){
		a[i].num=a[i-1].num&a[i].num;		
	}
	printf("%lld",a[m].num);
	return 0;
} 

