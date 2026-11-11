#include <bits/stdc++.h>
using namespace std;
const int N=1e6;  
int a[N];
int main()
{
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int uuu=0;
	  int ooo=0;
	int cnt=0;
	int ans=0;
	int cnt1=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	long long sum=0;
	for(int i=1;i<n;i++)
	{
	    sum+=a[i];
	    if(sum+m>=a[i+1]*i)
	    {
	    	ans=i+1;
		}
		
	}
	 cout<<ans;
}
     
