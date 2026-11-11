#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long x,as,ans;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	s=" ";
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>x>>c;
		as+=x;
		for(int j=1;j<=x;j++) s=s+c;
	}
	for(int i=1;i<=as/2;i++)
	{
		if(s[i]!=s[as-i+1])
		{
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
