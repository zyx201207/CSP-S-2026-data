#include<bits/stdc++.h>
using namespace std;
long long a[300000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	string s="";
	char c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		s.insert(s.end(),a[i],c);
	}
	long long l=0,r=s.size()-1;
	for(long long i=0;i<=s.size()-1;i++)
	{
		if(l==r)
		{
			break;
		}
		else
		{
			if(s[l]!=s[r])
			{
				cnt++;
			}	
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
