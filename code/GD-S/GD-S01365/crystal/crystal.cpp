#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned long long n,m,j=1,k=0;
	bool c=1;
	scanf("%lld %lld",&n,&m);
	if(n==1){
		cout<<"1";
		return 0;
	}
	long long a[n],z=1;
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=(i+1))c==0;
	}
	if(c==1){
		for(long long i=1;i<=m;i++){
			m-=i;
			z++;
		}cout<<z;
		return 0;
	}
	sort(a,a+n);
	j=1;
	for(long long i=1;i<n;i++){
		if(a[i]==a[i-1]){
			j++;
		}else{
			k=max(k,j);
			j=1;
		}
	}k=max(k,j);
	cout<<k;
	return 0;
}
