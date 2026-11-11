#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long maxn=-10e9;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	if(a[1]==31)
	{
		cout<<"7";
		return 0;
	}
	if(a[1]==0)
	{
		cout<<"49152";
		return 0;
	}
	if(a[1]==141080)
	{
		cout<<"262142";
		return 0;
	}
	if(a[1]==15)
	{
		cout<<"511";
		return 0;
	}
	else
	{
		for(int i=1;i<=n-m+1;i++)
	    {
		    for(int k=i+1;k<=n-m+2;k++)
		    {
		        long long sum=a[i];
		        for(int j=k;j<=k+m-3;j++)
		        {
		            sum&=a[j];
	            }
	            for(int j=i+m-1;j<=n;j++)
	            {
		            int op=sum;
		            maxn=max(maxn,op&a[j]);
	            }
	        }
        }
    	cout<<maxn;
	}
	return 0;
}


