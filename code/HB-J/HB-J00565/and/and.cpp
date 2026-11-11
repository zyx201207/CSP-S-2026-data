#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
long long maxn[200005]={};
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	for(long long i=1;i<=n;i++)maxn[i]=maxn[i-1]+a[i];
	long long i=2,c,e,f;
	c=(maxn[m]-maxn[0])/m;
	int k=1;
	for(long long j=1;j<=m;j++){
		b[k]=a[j];
		k++;
	}
	while(i+m<=n){
		e=(maxn[i+n]-maxn[i-1])/m;
		if(e>=c)c=e;
		k=1;
		for(long long j=i;j<=m;j++){
			b[k]=a[j];
			k++;
		}
		i++;
	}
	f=b[1];
	for(long long j=2;j<=m;j++){
		f=f&b[j];
	}
	cout<<f;
	return 0;
}
