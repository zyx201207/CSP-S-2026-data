#include <bits/stdc++.h>
using namespace std;
long long n,m,o[100000005];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long h=0;
	for(long long i=1;i<=n;i++)
	{
		long long p;
		
		cin>>p;
		o[i]=p;
		
	}
	
	
	for(long long  i=1;i<=n;i++)
	{
		
		for(long long j=i+1;j<=n;j++){
			h=max(h,o[i]&o[j]);
		}
	}
	
	cout<<h;

	
	return 0;
}
