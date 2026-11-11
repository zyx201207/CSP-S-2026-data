#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int cnt[M],ans[M];
int vis[M];
int now[M],last[M];
bool flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++)
			ans[a[i]]=i;
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]])
				for(int k=last[a[j]];k<j;k++)
					vis[a[k]]=0;
			vis[a[j]]=1,last[a[j]]=j;
		}
		for(int j=1;j<=n;j++)
			ans[a[j]]+=vis[a[j]],vis[a[j]]=0;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
/*
1 2 3 4 4 4 5 6

10 3
3 1 2 1 3 2 3 1 2 1

4 3
1 2 1 3
-------
1
1 2
(1 2 1)
(1 21) 3
1 2 2 1
尝试1：先模拟第一局再计算后面的 
尝试2：从纸牌最后一张开始往后推 
ans[a[n]]=n;
*/
