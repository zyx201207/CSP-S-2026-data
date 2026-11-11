#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],ans[N];
int card[N],ed=0;
void erase(int s)
{
	for(int i=0;i<ed;i++)
	{
		if(card[i]==s)
		{
			ed=i;
			break;
		}
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			erase(a[j]);
			card[ed]=a[j];
			ed++;
		}
		for(int i=0;i<ed;i++)
		{
			ans[card[i]]++;
		}
		ed=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
