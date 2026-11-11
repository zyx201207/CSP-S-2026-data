#include<bits/stdc++.h>
using namespace std;
int n,m,t;
long long ans=0;
vector<char>b;
struct sj{
	int a;
	char c;
}s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i].a);
		cin>>s[i].c;
		for(int j=1;j<=s[i].a;j++)
		{
			b.push_back(s[i].c);
		}
	}
	t=b.size()-1;
	for(int i=0;i<=t/2;i++)
	{
		if(b[i]!=b[t-i])
		{
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
