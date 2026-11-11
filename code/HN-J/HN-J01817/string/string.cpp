#include<bits/stdc++.h> 
using namespace std;
int n,a[200005],p,q,ans,cnt,o;
char c[200005],c1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		cnt+=a[i];
		
	}
	if(cnt%2==0) cnt=cnt/2;
	else cnt=cnt/2+1;
	

	

	q=n-1;
	while(cnt!=0)
	{
		if(cnt-a[p]<=0)
		{
			ans+=a[p]-2*(a[p]-cnt);
			break;
		}
		if(cnt-a[p]<=0)
		{
			ans+=a[q]-2*(a[q]-cnt);
			break;
		}
		if(c[p]==c[q])
		{
			
			
		
			if(a[p]<=a[q])
			{
			 o=a[q]-a[p];
			 ans+=o;
			 cout<<ans<<endl;
			 cnt-=a[p];
			
			}
			else
			{	
			 o=a[p]-a[q];
			 
			 ans+=o;
			 cout<<ans<<endl;
			 cnt-=a[q];
			 
			}
		}
		else 
		{ 
			if(a[p]<=a[q])
			{
			 o=a[q]-a[p];
			 a[p+1]-=o;
			 ans+=a[p];
			 
			cnt-=a[q];
			}
			else
			{	
			 o=a[p]-a[q];
			 
			 ans+=a[q];
			 
			 cnt-=a[q];
			}
			
		}
		
		
		q--;
		p++;
		
		
		 
	}
	cout<<ans;
	return 0;
}

