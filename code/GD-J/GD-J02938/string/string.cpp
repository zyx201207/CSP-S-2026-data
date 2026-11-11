#include <bits/stdc++.h>
using namespace std;
string s;
int n,l,r,ans;


int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++)
		{
			s+=y;
		}
	}
	int len=s.length();
	len/=2;
	if(len*2!=s.length())
	{
		l=len,r=len+2;
	}
	else
	{
		l=len,r=len+1;
	}
	l--;
	r--;
	
	
	for(int i=1;i<=len;i++)
	{
		if(s[l]!=s[r])
		{
			ans++;
			
		}
		l--;
		r++;
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
