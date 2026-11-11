#include<bits/stdc++.h>
using namespace std;
#define int long long
struct str
{
	int k;
	char c;	
}s[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].k>>s[i].c;
		len+=s[i].k;
	}
	int ans=0;
	int l=1;
	int r=n;
	while(l<r)
	{
		if(s[l].k==0)
		{
			l++;
		}
		if(s[r].k==0)
		{
			r--;
		}
		if(s[l].c==s[r].c)
		{
			int tmp=min(s[l].k,s[r].k);
			s[l].k-=tmp;
			s[r].k-=tmp;
		}
		else
		{
			int tmp=min(s[l].k,s[r].k);
			ans+=tmp;
			s[l].k-=tmp;
			s[r].k-=tmp;
		}
	}
	cout<<ans;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
