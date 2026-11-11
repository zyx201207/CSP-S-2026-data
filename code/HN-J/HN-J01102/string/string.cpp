#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt[200010];
char ch[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>cnt[i]>>ch[i];
	}
	int l=1,r=n,sl=cnt[1],sr=cnt[n],ans=0;
	while(l<r)
	{
		if(ch[l]!=ch[r])
		{
			if(sl<sr)
			{
				sr-=sl;
				ans+=sl;
				sl=cnt[++l];
			}
			else if(sl==sr)
			{
				ans+=sl;
				sl=cnt[++l],sr=cnt[--r];
			}
			else
			{
				sl-=sr;
				ans+=sr;
				sr=cnt[--r];
			}
		}
		else
		{
			if(sl<sr)
			{
				sr-=sl;
				sl=cnt[++l];
			}
			else if(sl==sr)
			{
				sl=cnt[++l],sr=cnt[--r];
			}
			else
			{
				sl-=sr;
				sr=cnt[--r];
			}
		}
	}
	cout<<ans<<endl;
}

