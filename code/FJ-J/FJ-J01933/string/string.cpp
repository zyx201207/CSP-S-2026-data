#include<bits/stdc++.h>
using namespace std;
int ans=0;
string s,b;
long long n=0;
long long a[200010]={0};
char c[200010]={0};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i];j>0;j--)
		{
			s[j]=c[i];
			b=s[j];
		}
	}
	int l=1;
	int r=b.size();
	for(int i=1;i<=n;i++)
	for(int i=1;i<=(l+r)/2;i++)
	{
		if(b[l]==b[r])
		{
			l++;
			r--;
		}
		else
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}	
