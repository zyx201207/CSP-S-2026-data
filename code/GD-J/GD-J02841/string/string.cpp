#include<bits/stdc++.h>
using namespace std;
char c[2*100000+5];
string st;
long long a[2*100000+5],n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cin>>c[i];
		for(long long j=1;j<=a[i];j++) st=st+c[i];
	}
	for(int i=0;i+i<=st.size()-1;i++)
	{
		if(st[i]!=st[st.size()-1-i])
		{
			ans++;
			st[st.size()-1-i]=st[i];
		}
	}
	printf("%lld",ans);
	return 0;
}
