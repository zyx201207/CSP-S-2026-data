#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],diff[500005],nxt[500005],cur[500005],ans[500005];
vector<int>pos[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],pos[a[i]].push_back(i);
	for(int i=1;i<=m;i++)
		for(int j=0;j<pos[i].size()-1;j++)
			nxt[pos[i][j]]=pos[i][j+1];
	for(int i=1;i<=n;i++){
		int r=nxt[i];
		if(r==0)r=i;
		cur[i]=cur[i-1]+diff[i-1];
		diff[i]+=i-cur[i];
		diff[r]-=i-cur[i];
	}
	for(int i=1;i<=n;i++)
		diff[i]+=diff[i-1],ans[a[i]]=max(ans[a[i]],n-(diff[i]+(n-i)));
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
}
