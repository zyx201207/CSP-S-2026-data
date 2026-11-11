#include <bits/stdc++.h>
using namespace std;
string b[200005];
int a[200005];
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	int z=1,op=2;
	int lj,q,cnt=0,ans,nb=0,nic=2;
	string kb,p;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(n>=z)
	{
		lj=a[z];
		kb=b[z];
		q=a[n];
		p=b[n];
		if(nic==1)
		{
			lj+=nb;
		}
		else if(nic==0)
		{
			q+=nb;
		}
		nic=2;
		if(op==1)
		{
			lj-=ans;
			ans=0;
			if(lj<0)
			{
				nb=lj;
				z++;
				nic=1;
			continue;
			}
		}
		else if(op==0)
		{
			q-=ans;
			ans=0;
			if(q<0)
			{
				nb=q;
				n--;
				nic=0;
				continue;
			}
		}
		if(lj>q)
		{
			op=1;
			n--;			
				if(kb==p)
				{
					ans=q;					
					continue;
				}
				else
				{
				ans=q;
					cnt+=q;
					
				}
			
		}
		else if(lj<q)
		{
			op=0;
			z++;
				if(kb==p)
				{
					ans=lj;					
					
				}
				else
				{
					cnt+=lj;
					
				}
		}
	else
	{
n--;
		z++;
		if(kb!=p)
		{
			cnt+=lj;
		}
	}
	 } 
	 cout<<cnt;
	return 0;
}

