#include<bits/stdc++.h>
using namespace std;
//define int long long
//define int __int128
const int N=1e6,A=1e9;
int n,m,a[N],nxt[N],ans[N],id[N];
vector<int>e[N];
int bfs(int l,int r)
{
	if(l==r){ans[a[l]]++;int next=nxt[a[l]];nxt[a[l]]=l;return next;}
	int idz=0,idy,idx=a[r];
	vector<int>f;
	for(int i=id[r];i>-1&&e[idx][i]>=l;i--)f.push_back(e[idx][i]);
	int len=f.size();
	f.push_back(l-1);
	for(int i=0;i<len;i++)
	{
		if(f[i]-1==f[i+1])continue;
		idy=bfs(f[i+1]+1,f[i]-1);
//		cout<<f[i+1]<<' '<<f[i]<<' '<<idy<<"\n";
		if(idy>r&&idy<nxt[a[r]])idz=(idz==0?nxt[a[idy]]:idz);
	}
	ans[a[r]]+=(r-max(idz,l)+1);
	int next=nxt[a[r]];
	nxt[a[r]]=r;
	return next;
}
signed main()
{

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//freopen(".in","w",stdout);
	//freopen(".out","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)nxt[i]=n+1;
	for(int i=1;i<=n;i++){cin>>a[i];e[a[i]].push_back(i);id[i]=e[a[i]].size()-1;}
	bfs(1,n);
//	for(int i=1;i<=n;i++)cout<<id[i]<<' ';
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

