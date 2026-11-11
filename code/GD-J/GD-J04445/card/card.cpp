//CAN I AK CSPJ?Trick or point~
#include<iostream>
#include<cstring> 
#include<vector>
using namespace std;
int n,m,a[500005],nxt[500005],now[300005];
bool flag=1,live[300005];
int main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]<a[i-1])flag=0;
	}
	for(int i = n;i>=1;i--)
		if(now[a[i]])
		{
			nxt[i]=now[a[i]];
			now[a[i]]=i;
		}
		else now[a[i]]=i;
	if(flag)
	{
		for(int i = 1;i<=n;i++)nxt[i]++;
		for(int i = 1;i<=m;i++)nxt[i]+=nxt[i-1];
		for(int i = 1;i<=m;i++)cout << nxt[i] << ' ';
		return 0; 
	}
	memset(now,0,sizeof now);
	for(int i = 1;i<=n;i++)
	{
		memset(live,0,sizeof live);
		int cur=i;
		while(cur<=n)
		{
			live[a[cur]]=1;
			if(nxt[cur])cur=nxt[cur];
			else cur++;
		}
		for(int i = 1;i<=m;i++)now[i]+=live[i];
	}
	for(int i = 1;i<=m;i++)cout << now[i] << ' ';
	return 0;
}
