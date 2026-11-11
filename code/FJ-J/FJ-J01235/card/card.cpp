#include<bits/stdc++.h>
using namespace std;
int a[500005],tot[500005],n,m,now[500005],len;
bool check(int x)
{
	for(int i=1;i<=len;++i)
		if(now[i]==x)
			return true;
	return false;
}
void pop(int x)
{
	while(now[len]!=x)
	{
		--len;
	}
	--len;
}
void play(int x)
{
	memset(now,0,sizeof(now));
	len=0;
	for(int i=x;i<=n;++i)
	{
		if(check(a[i]))
		{
			pop(a[i]);
		}
		now[++len]=a[i];
	}
	/*for(int i=1;i<=len;++i)
		cout<<now[i]<<" ";
	cout<<"\n";*/
	for(int i=1;i<=len;++i)
		++tot[now[i]];
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
		play(i);
	for(int i=1;i<=m;++i)
		cout<<tot[i]<<" ";
	return 0;
}
