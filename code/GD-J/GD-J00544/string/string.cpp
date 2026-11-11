#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,maxx;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		maxx=max(maxx,a[i]);
	}
	if(n*maxx<=100000000)
	{
		string s={};
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s+=c[i];
			}
		}
		int l=s.size();
		string s1={};
		for(int i=l-1;i>=0;i--) s1+=s[i]; 
		for(int i=0;i<l;i++)
		{
			if(s[i]!=s1[i]) 
			{
				cnt++;
			}
		}
		cout<<cnt/2;
	}
	else cout<<0;
	return 0;
}
