#include<bits/stdc++.h>
#include<cstring>
using namespace std;
const int maxn=200005;
int n;
long long a[maxn];
char c[maxn];
string s;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cin>>c[i];
		if(i>1)
			if(c[i]!=c[i-1])
				flag=false;
		for(long long j=1;j<=a[i];j++)
			s+=c[i];
	}
	if(flag)
	{
		printf("0");
		return 0;
	}
	long long len=s.size();
	for(long long i=0;i<len/2;i++)
		if(s[i]!=s[len-1-i])
			ans++;
	printf("%lld",ans);
	return 0;
}
