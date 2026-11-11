#include<bits/stdc++.h>
using namespace std;
bool N[40005][40005];
pair<int,int> cnt[1005];
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.second < b.second;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i = 1;i <= t;i++)
	{
		memset(cnt,0,sizeof(cnt));
		int n,k;
		cin>>n>>k;
		for(int j = 1;j <= n;j++)
		{
			int u,v;
			cin>>u>>v;
			N[u][v] = true;
			cnt[u].first = u;
			cnt[u].second++;
			cnt[v].first = v;
			cnt[v].second++;
		}
		sort(cnt + 1,cnt + n,cmp);
		int cnt_dis = 0;
		for(int j = k + 1;j <= n;j++)
		{
			int dis = INT_MAX;
			for(int l = 1;l <= k;l++)
			{
				dis = min(dis,j - l);
			}
			cnt_dis += dis;
		}
		cout<<cnt_dis;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
