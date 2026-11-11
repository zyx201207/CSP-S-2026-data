#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(long long i=1;i<=n;i++)cin>>a[i];
	int q;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i+1;j<=n;j++)
		{
			if(a[i]<a[j])swap(a[i],a[j]);
		}
	 } 
	 long long b[n]={0};
	 for(long long i=1;i<=n;i++)
	 {
	 	if(a[i]==a[i+1])b[i]=1;
	  } 
	  long long ansa=0;
	  for(long long i=1;i<=n;i++)
	  	if(b[i]==1)ansa++; 
	  cout<<a[m+ansa]; 
	return 0;
} 
//Trick||Treat!
