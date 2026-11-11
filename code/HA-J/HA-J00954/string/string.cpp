#include<bits/stdc++.h>
using namespace std;
const int N=123029;
struct node
{
	long long c;
	char t;
	int ti;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,z=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].c>>a[i].t;
		s+=a[i].t;
	}
//	for(int i=1;i<=n;i++)
//	{
//		if(a[i].c%2==0)
//		{
//			s+=a[i].t;
//		}
//		else
//		{
//			s+=a[i].t;
//		}
//	}
	long long ans=0;
	for(int i=0,j=s.size()-1;i<=j;)
	{
		if(s[i]!=s[j])
		{
			if(a[i+1].c==a[j+1].c)
			{
				
				ans+=a[i+1].c;
				i++;
				j--;
			}
			else if(a[i+1].c>a[j+1].c)
			{
				ans+=a[j+1].c;
				a[i+1].c-=a[j+1].c;
				
				j--;
			}
			else if(a[i+1].c<a[j+1].c)
			{
				ans+=a[i+1].c;
				a[j+1].c-=a[i+1].c;
				i++;
			}
		}
		else if(a[i+1].c<a[j+1].c)
		{
			
			a[j+1].c-=a[i+1].c;
			i++;
		}
		else if(a[i+1].c>a[j+1].c)
		{
			
			a[i+1].c-=a[j+1].c;
			j--;
		}
		else 
		{
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
