#include<bits/stdc++.h> 
using namespace std;
unsigned long long int n,m,maxn=0;
long long int a[100001];
bool cmp(long long int x,long long int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(long long int i=1;i<=n-1;i++){
		unsigned long long int m1=m,h=1;
		long long int now=a[i];
		long long int j=i+1;
		while((m1>=now-a[j])&&(j<=n)&&(m1>0)){
			h++;
			m1-=(now-a[j]);
			j++;
		}
		maxn=max(maxn,h);
	}
	printf("%lld",maxn);
	return 0;
}
