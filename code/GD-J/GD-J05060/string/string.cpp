#include<bits/stdc++.h>
using namespace std;
struct nx
{
	int n;
	char x;
}a[200005];
long long t,ans,p,a1[200005]; 
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a[i].n>>a[i].x;
		s+=a[i].x;
		a1[i]=a[i].n;
	}
	if(s.size()<200000000)
	{
		for(int i=0,j=s.size()-1;i<=j;i++,j--)
		{
			if(s[i]!=s[j]) p++;
		}
		cout<<p;
		return 0;
	}
	int k=s.size()%2;
	if(k==1)
	{
		for(int i=0;i<s.size()/2;i++)
		{
			if(s[i]!=s[s.size()-i-1]||a[i].n!=a1[i]) 
			{
				if(s.size()-i-2>s.size()/2||i+1<s.size()/2)
				{
					if(a[s.size()-i-1].n>=a[i].n) a[s.size()-i-2].n+=a[s.size()-i-1].n-a[i].n,p+=a[i].n;
					else a[s.size()-i-2].n-=a[s.size()-i-1].n-a[i].n,p+=a[i].n;
				}
				else if(s.size()-i-2==s.size()/2)
				{
					p+=min(a[i].n,a[s.size()-i-1].n);
					p+=abs(a[i].n-a[s.size()-i-1].n);
				}
			}
		}
	}
	else
	{
		for(int i=0;i<s.size()/2;i++)
		{
			if(s[i]!=s[s.size()-i-1]||a[i].n!=a1[i]) 
			{
				if(s.size()-i-2>s.size()/2-1||i+1<s.size()/2)
				{
					if(a[s.size()-i-1].n>=a[i].n) a[s.size()-i-2].n+=a[s.size()-i-1].n-a[i].n,p+=a[i].n;
					else a[s.size()-i-2].n-=a[s.size()-i-1].n-a[i].n,p+=a[i].n;
				}
				else if(s.size()-i-2==s.size()/2-1)
				{
					p+=min(a[i].n,a[s.size()-i-1].n);
				}
			}
		}
	}
	cout<<p;
	
	return 0;
} 
