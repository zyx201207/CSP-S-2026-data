#include<bits/stdc++.h>
using namespace std;
string s1;
long long cnt,z,ans,sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long q;
		cin>>q;
		char s;
		cin>>s;
		for(int j=1;j<=q;j++)
		{
			s1+=s;
		}
		cnt+=q;
	}
	if(cnt%2==1)
	{
		z=(cnt+1)/2;
		ans=2;
	}
	else 
	{
		z=cnt/2;
		ans=1;
	}

	for(int i=z;i<cnt;i++)
	{
		if(s1[i]!=s1[i-ans])
		{
			sum++;
		}
		ans+=2;
	}
	cout<<sum;
	return 0;
}
