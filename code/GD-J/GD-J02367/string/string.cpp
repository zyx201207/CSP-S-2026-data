#include<bits/stdc++.h> 
using namespace std;

const int N=2e5+8;
int n,l,r;
pair<long long,char> s[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	long long a;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		s[i].first=a;
		s[i].second=c;
	}
	
	l=1,r=n;
	long long a1=s[l].first,a2=s[r].first,ans=0;
	char c1=s[l].second,c2=s[r].second;

	while(l<r)
	{
		if(a1==a2)
		{
			if(c1!=c2)
			{
				ans+=a2;
			}
			l++;r--;
			a1=s[l].first,c1=s[l].second;
			a2=s[r].first,c2=s[r].second;
		}
		else if(a1<a2)
		{
			if(c1!=c2)
			{
				ans+=a1;
			}
			l++;
			a2-=a1;
			a1=s[l].first,c1=s[l].second;
		}
		else
		{
			if(c1!=c2)
			{
				ans+=a2;
			}
			r--;
			a1-=a2;
			a2=s[r].first,c2=s[r].second;
		}
	}
	
	cout<<ans<<'\n';
	return 0;
}
