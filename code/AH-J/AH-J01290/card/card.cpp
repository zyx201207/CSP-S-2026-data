#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int cnt[N];
int pr[N];
int ne[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	memset(ne,0x3f3f3f,sizeof(ne));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ne[pr[a[i]]]=i;
		pr[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			while(ne[j]<=n)j=ne[j];
			cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
