#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
long long sum;
struct numb{
	long long d;
	int bit;
} a[200001];
int bitsolve(int x){
	int sum=0,tmp=0;
	while(x){
		tmp=x-(x^1);
		x=x>>1;
		if(tmp==1)sum++;
	}
	return sum;
}
bool cmp(numb x,numb y){
	return x.bit>y.bit;
}
int main(){
	freopen("and.in","r",stdin);
	/*提交时去掉freopen！！！*/
	freopen("and.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].d);
		a[i].bit=bitsolve(a[i].d);
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1].d;
	for(int i=2;i<=m;i++)
		sum&=a[i].d;
	printf("%lld\n",sum);
	return 0;
}
