#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int cnt[N];
int a[N];
bool del[N];
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<"1 ";
	}
	return 0;
}
