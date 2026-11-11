#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node
{
	int x;
	char c;
}s[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].x>>s[i].c;
	int l=1,r=n,ans=0;
	while(l<r)
	{
		int tmp=min(s[l].x,s[r].x);
		if(s[l].c!=s[r].c) ans+=tmp;
		s[l].x-=tmp,s[r].x-=tmp;
		if(!s[l].x) l++;
		if(!s[r].x) r--;
	}
	cout<<ans;
	return 0;
}

