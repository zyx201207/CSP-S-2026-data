#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a[10000];
	long long b[10000];
	long long n,m,k;
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%lld",&a[1+i]);
		
		
	}
	for(int c=0;c<n;++c){
		if(a[1+c]<=a[2+c]){
		b[1+c]= a[2+c]-a[1+c];
	}else{
		b[1+c]=a[1+c]-a[2+c];
	}
	
	k++;
	}
	cout<<k-2; 
	
	 
	
	return 0;
}
