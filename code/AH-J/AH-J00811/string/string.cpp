#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
long long ans=0;
struct Node{
	long long len;
	char ch;
}s[N];

signed main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	long long cnt=0;
	
	for(int i=1;i<=n;i++)
		cin>>s[i].len>>s[i].ch,cnt+=s[i].len;	
	
	int l=1,r=n;
	long long ls=s[l].len,rs=s[r].len;
	while(r-l>0)
	{
		
			if(ls<rs)
			{
				if(s[l].ch!=s[r].ch) ans+=ls;
				l++;
				rs-=ls;
				ls=s[l].len;
			}
			else if(ls==rs)
			{
				if(s[l].ch!=s[r].ch) ans+=ls;
				l++,r--;
				rs=s[r].len;
				ls=s[l].len;
			}	
			else if(ls>rs)
			{
				if(s[l].ch!=s[r].ch) ans+=rs;
				ls-=rs;
				r--;
				rs=s[r].len;
			}	
			
	}
	cout<<ans;
	return 0;
}	
