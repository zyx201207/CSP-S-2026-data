#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+9;
int a[N];
long long st[N],ans[N],tot;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;++i)
	{
		cin >> a[i];
	}
	for(int game=1;game<=n;++game)
	{
		for(int i=game;i<=n;++i)
		{
			for(int j = 1;j<=tot;++j)
			{
				if(st[j] == a[i])
				{
					tot = j-1;
					break;
				}
			}
			st[++tot] = a[i];
		}
		for(int i=1;i<=tot;++i)
		{
			ans[st[i]]++;
		}
		memset(st,0,sizeof(st));
	}
	for(int i=1;i<=m;++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
