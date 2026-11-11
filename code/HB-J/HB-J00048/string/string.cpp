#include<bits/stdc++.h>
using namespace std;
int n,len,ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int cnt;
		char a;
		cin>>cnt>>a;
		for(int j=1;j<=cnt;j++)
		{
			s+=a;
		}
	}
	int len=s.size();
	for(int i=0;i<=len/2;i++)
	{
		if(s[i]!=s[len-1-i])
			ans++;
	}
	printf("%d",ans);
	return 0;
}
