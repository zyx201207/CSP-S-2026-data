#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
char s[N];
int cnt[N];
int l;
ll sum,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&cnt[i],&s[i]);
	}
	// for(int i=1;i<=n;i++)
	// {
	//	 cout<<cnt[i]<<" "<<s[i]<<"\n";
	// }
	int t=n;
	for(int i=1;i<=n;i++)
	{
		while(cnt[i]&&i<t)
		{
			int min1=min(cnt[i],cnt[t]);
			cnt[i]-=min1;
			cnt[t]-=min1;
			if(s[i]!=s[t])	ans+=min1;
			if(!cnt[t])	t--;
		}
	}
	printf("%lld",ans);
	return 0;
}

