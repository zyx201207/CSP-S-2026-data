#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 5;
ll n,a[N],cnt,ans=(1<<30)-1,m;
vector<ll>t[35];
bool flag=0,d[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=29;j>=0;j--)	if(a[i]&(1<<j)) t[j].push_back(i);
	for(int j=29;j>=0;j--)
	{
		if(t[j].size()>=m)
		{
			if(!flag) 
			{
				for(auto &e:t[j]) d[e]=1;
				flag=1;
			}
			else 
			{
				bool s[N]={0};
				cnt=0;
				for(auto &e:t[j])	if(d[e]) cnt++,s[e]=1;
				if(cnt<m) continue;
				swap(d,s);
			}
		}
	}
	for(int i=1;i<=n;i++) if(d[i]) ans=(ans&a[i]);
	cout<<ans;
	return 0;
}
