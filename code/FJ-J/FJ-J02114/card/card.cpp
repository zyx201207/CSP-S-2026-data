#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10,MAXM=3e5+10;
int n,m,a[MAXN],have,ans[MAXM];
char card[MAXN];
string now;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],card[i]=a[i]+'0';
	for(int right=1;right<=n;right++)
	{
		now="";
		for(int i=right;i<=n;i++)
		{
			if(now.find(card[i])!=-1)
			{
				have=now.find(card[i]);
				now=now.substr(0,have);
			}
			now=now+card[i];
		}
		for(int i=1;i<=m;i++)
		{
			ans[i]+=(now.find((char)(i+'0'))!=-1);
		}
	}
	for(int i=1;i<=m;i++) cout << ans[i] << ' ';
	return 0;
}
