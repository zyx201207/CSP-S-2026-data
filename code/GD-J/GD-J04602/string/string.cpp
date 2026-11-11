#include <bits/stdc++.h>
using namespace std;
int cnt[200020];
char ch[200020];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>cnt[i]>>ch[i];
	}
	long long l=1,r=n,ans=0;
	while(l<r)
	{
		int t=min(cnt[l],cnt[r]);
		if(ch[l]!=ch[r])
		{
			//cout<<t<<endl;
			ans+=t;
			cnt[l]-=t;
			cnt[r]-=t;
		}
		else
		{
			cnt[l]-=t;
			cnt[r]-=t;
		}
		if(!cnt[l])l++;
		if(!cnt[r])r--;
	}
	cout<<ans;
}
