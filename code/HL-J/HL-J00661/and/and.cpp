#include<bits/stdc++.h>
using namespace std;
vector<int>a;
vector<int>b;
vector<int>c; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=-10;
	int ans=0;
	cin>>n>>m;
	a.resize(n);
	b.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>mx)
		{
			mx=a[i];
		}
	}
	for(int i=0;i<n;i+=2)
	{
		int j=0;
		while(a[i])
		{
			b[j]=a[i]%2;
			a[i]/=2;
			j++;
		}
		j=0;
		reverse(b.begin(),b.end());
		while(a[i+1])
		{
			c[j]=a[i+1]%2;
			a[i+1]/=2;
			j++;
		}
		reverse(c.begin(),c.end());
		j=0;
		int ll=max(b.size(),c.size());
		while(ll--)
		{
			if(b[j]==c[j])
			{
				ans+=pow(2,j);
			}
			j++;
			
		}
		
	}
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	
	cout<<ans;
	return 0;
} 
