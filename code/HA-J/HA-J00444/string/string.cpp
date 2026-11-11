#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char f[100005];
	long long a[100005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>f[i];
	}
	int r=0;
	for(int i=1;i<n;i++)
	{
		if(f[i]!=f[i+1])
		{
			r=1;
		}
	}
	if(r==0)
	{
		cout<<0;
		return 0;
	}
	string s;
	long long y=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=y;j<=y+a[i];j++)
	    {
	    	s[j]=f[j];
        }
        y+=a[i];
    }
    long long o=0;
    for(int i=y;i>=y/2;i--)
	{
		int h=y/2-i;
		if(s[i]!=s[h])
		{
			o++;
		}
    }
    cout<<o;
	return 0;
}
