#include<bits/stdc++.h>
using namespace std;
struct node{
	long long k;
	long long k2s;
}a[200005];
int n,m;
bool cmp(node x,node y){
	if(x.k2s!=y.k2s)return x.k2s>y.k2s;
	return x.k>y.k;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].k);
		long long y=a[i].k;
		while(y){
			if(y%2)a[i].k2s++;
			y/=2;
		}
	}
	sort(a+1,a+1+n,cmp);
	long long x=a[1].k;
	for(int i=2;i<=m;i++){
		x=(x&a[i].k);
	}
	printf("%d",x);
	return 0;
}
