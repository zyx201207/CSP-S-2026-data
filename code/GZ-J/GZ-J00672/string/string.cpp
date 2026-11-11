//GZ-J00672,魏晨睿，凯里学院附属中学   
#include<bits/stdc++.h>
using namespace std;
long long a[500001],n,p=0;
string b[500001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	cin>>b[i];
	}
	if(n>2)
	{ 
	long long l=1,r=n;
	while(l<r)
	{
		if(l==r||r-l==1)break;
		if(b[l]==b[r]&&a[l]==a[r])
		{
		
			l++;
		    r--;
		    continue;
	    }
		else if(b[l]==b[r]&&a[l]!=a[r])
		{
			int x=a[l],y=a[r];
			p=p+max(x,y)-min(x,y);
			
			l++;
		    r--;
		    continue;
		}
		else if(b[l]!=b[r])
		{
			if(a[l]>=a[r])
			{
				p=p+a[l]; 
			} 
			else
			{
			 	p=p+a[r]; 
			} 
		}
			l++;
		r--;
	}
    }   
    else
    {
    	long long c=1,d=n;
    	if(b[c]==b[d]||a[c]==a[d])p=0;
    	else 
    	{
    		int x=a[c],y=a[d];
			p=p+max(x,y)-min(x,y);
		}
	}
	long long z=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==b[1])z++;
	}
	if(z==n)
	{
		cout<<0;
		return 0;
	}
	else
	cout<<p;
	return 0;
}
