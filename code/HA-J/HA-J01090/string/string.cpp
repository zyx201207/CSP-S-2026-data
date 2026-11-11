#include<bits/stdc++.h>
using namespace std;
long long n,res,x;
char c[200010];
long long a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		
	}
	x=n;
	for(int i=1;i<=n;i=i)
	{
		if(i==x) break;
		if(a[i]>0)
		{
			if(c[i]!=c[x])
			{
				if(a[i]>=a[x])
				{
					res+=a[x]; 
					a[i]-=a[x];
					a[x]=0;
					x--;
				}
				else
				{
					res+=a[i];
					a[x]-=a[i];
					a[i]=0;
					i++;
				}
			}
			else
			{
				if(a[i]>=a[x])
				{ 
					a[i]-=a[x];
					a[x]=0;
					x--;
				}
				else
				{
					a[x]-=a[i];
					a[i]=0;
					i++;
				}
			}
		}
		else i++;
	}
	cout<<res<<endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
} 
