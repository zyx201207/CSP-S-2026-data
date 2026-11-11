#include<bits/stdc++.h>
using namespace std;
/*
10 3
3 1 2 1 3 2 3 1 2 1
10 3 3
*/
int a[200005],ans[200005];
bool vis[200005];
int n,m;
void in() {
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	return ;
}
void work() {
	for(int k=1;k<=n;k++)
	{
		memset(vis,0,sizeof vis);
		vector<int>q;
		for(int j=k;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				q.push_back(a[j]);
				vis[a[j]]=1;
			}else 
			{
				while(q.back()!=a[j])
				{
					vis[q.back()]=0;
					q.pop_back();
				}
//				q.push_back(a[j]);
				//memset(vis,0,sizeof vis);
				vis[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)if(vis[j])ans[j]++;
//		while(!q.empty())
//		{
//			ans[q.back()]++;
//			q.pop_back();
//		}
	}
	return ;
}
void out() {
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return ;
}
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	in();
	work();
	out();
	return 0;
}

