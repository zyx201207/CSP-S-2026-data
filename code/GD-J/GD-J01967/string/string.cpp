#include<bits/stdc++.h>
using namespace std;
long long n,m[200005],cnt,ans;
string t;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i]>>s;
		cnt+=m[i];
		for(int j=1;j<=m[i];j++)
		{
			t+=s;
		}
	}
	for(int i=0;i<=(cnt+1)/2-1;i++)
	{
		if(t[i]!=t[cnt-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
}

