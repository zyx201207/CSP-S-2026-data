#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,len[200010],cnt;
char c[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>len[i]>>c[i];
	int l=1,r=n;
	while(l<r)
	{
		if(len[l]==len[r])
		{
			if(c[l]!=c[r]) cnt+=len[l];
			l++;
			r--;
		}
		else if(len[l]<len[r])
		{
			if(c[l]!=c[r]) cnt+=len[l];
			len[r]-=len[l];
			l++;
		}
		else
		{
			if(c[l]!=c[r]) cnt+=len[r];
			len[l]-=len[r];
			r--;
		}
	}
	cout<<cnt;
}
/*
wo yao shang!!!
*/
