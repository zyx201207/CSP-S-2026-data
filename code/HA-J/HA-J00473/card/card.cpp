#include<bits/stdc++.h>
using namespace std;
typedef long long lnt;
const int N = 5e5 + 5;
const int M = 3e5+5;
int a[N];
int n,m;
int nex[N],last[N],ans[M],cnt[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	a[0]=0;
	for(int i =1 ; i <= n; i++)
	cin>>a[i];
	memset(last,0,sizeof(last));
	memset(nex,0,sizeof(nex));
	for(int i = 1; i <= n; i++)
	{
		nex[last[a[i]]] = i;
		last[a[i]]=i;	
	} 	
	for(int i = 1; i <= n; i++)
	{
		for(int j = i;j <=n; j++)
		{
			ans[a[j]]++;
		    while(nex[j])j=nex[j];
		}
	}
	for(int i = 1; i <= m; i++)cout << ans[i] << " ";
	return 0;
} 	
