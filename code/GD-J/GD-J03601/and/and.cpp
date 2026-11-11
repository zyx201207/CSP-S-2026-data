#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000005],ans=-1,sum=0,cnt=0,j;
long long b[10000005]={0},c[10000005],d[10000005];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++){
		cin >>a[i];
	}
	for(long long i=0;i<n;i++){
		c[i]=a[i];
	}
	for(long long i=0;i<n;i++){
		if(c[i]%2==1){
			b[i]++;
		}
		c[i]/=2;
	}
	for(long long i=0;i<n;i++){
		for(j=1;j<=m;j++){
			sum+=b[i];
			c[i]=true;
		}
		if(ans<sum){
			ans=sum;
			d[j]=a[i];
		}
	} 
	for(int i=0;i<n;i++){
		if(c[i]==true){
			cnt=cnt&a[i];
		}
	}
	printf("%lld",cnt);
}
