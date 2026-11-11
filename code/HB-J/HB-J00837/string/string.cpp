#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long ans,l;
string s;
char a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %s",&l,&a);
		while(l--)s+=a;
	}
	long long len=s.size();
	for(int i=0;i<=(len-1)/2;i++)
	{
		if(s[i]!=s[len-1-i])
		{
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
