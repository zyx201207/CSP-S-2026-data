#include<bits/stdc++.h>
using namespace std;
long long n,m,f[1000010],haha[1000010],xixi[10000010],sum=-0x3f3f3f;

long long dp(long long a,long long b){
	if(a==n-1)return 2;
	long long c=1;
	
	for(long long i=a;i<n-1;i++){
		b-=(haha[i]*c);
		if(b<0)return c;
		if((i==n-1&&b>-1)||c>50001)return 0;
		c++;
	}
	
};
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;

	for(long long i=0;i<n;i++)cin>>f[i];
	sort(f,f+n);
	for(long long i=1;i<n;i++)haha[i]=f[i]-f[i-1];
	for(long long i=1;i<n;i++){
		xixi[i]=dp(i,m);
	}

	for(long long i=1;i<n;i++)if(xixi[i]>sum)sum=xixi[i];
	cout<<sum;
	
	return 0; 
} 
