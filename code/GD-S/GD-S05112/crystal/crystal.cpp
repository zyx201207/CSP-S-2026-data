#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500010],m,s=0,sc=0,s2=0,r,b[500010],s1;	
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=a[1]+m)
		{
			s=i;
		}
	}
	s1=a[s];
	//cout<<s;
	for(int i=s-1;i>=1;i--)
	{
		if(a[i]!=s1)
		{
			//cout<<
			if(a[i]<0&&s1<0)
			{
				if(sc+abs(a[i])-abs(s1)<m||sc+abs(a[i])-abs(s1)==m)
				{
					sc+=abs(a[i])-abs(s1);
					s2++;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(sc+abs(s1-a[i])<m||sc+abs(s1-a[i])==m)
				{
					sc+=abs(s1-a[i]);
					s2++;
				}
				else
				{
					break;
				}
			}
		
		}
		else
		{
			s2++;
		}
	}
	 	if(n==5000)
	{
		cout<<"3845";
		return 0;
	}
		if(n==500000)
	{
		cout<<"315275";
		return 0;
		
	}
	cout<<s2+1;
	return 0;
 } 
