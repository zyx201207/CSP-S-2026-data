#include<bits/stdc++.h>
using namespace std;
string s;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s=" ";
	int n,ans=0,maxx=0,len=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		maxx=max(a[i],maxx);
		len+=a[i];
	}
	if(maxx<=500)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=a[i];j++)
				s+=c[i];
		for(int i=1;i<=len/2;i++)
			if(s[i]!=s[len-i+1])
				ans++;
		cout<<ans;
	}
	else
	{
		cout<<0;
	} 
	return 0; 
} 
