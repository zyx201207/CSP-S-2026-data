#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001];
long long x,xi,mi;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) a[i]=a[i+1]-a[i];
	a[n]=0;
	for(int i=1;i<=n;i++){
		xi=1;
		mi=m;
		for(int j=i,l=1;j<=n;j++,l++){
			if(mi>=a[j]*l){
				mi-=a[j]*l;
				xi++;
			}
			else break;
		}
		x=max(x,xi);
	}
	printf("%lld",x);
	return 0;
} 
