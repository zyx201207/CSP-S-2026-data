#include<bits/stdc++.h>
using namespace std;
int a[10000000],maxx,ans,o,n,m,k,aaa;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	aaa=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];

	}
	sort(a,a+n-1);
	
	maxx=0;
	o=0;
	for(long long gg=0;gg<a[n-1];gg++)
	{
		k=gg;
			for(long long j=0;j<n;j++)
		{
			
			
			o=0;
			ans=0;
			for(long long i=j;i<n;i++)
			{
				
				//if(i==k) continue;
				long long y=k-a[i];
				if(y<0) y=-y;
				if(y<m )
				{
					ans+=y;
					o++;
				}
				if(ans>m)
				{
					break;
				}
				if(ans<=m)
				{
					if(o>maxx) maxx=o;
				}
				
			}	
		}	
	}
//ºÃÂé·³ÄÅ 
	cout<<maxx;
	return 0;
} 
