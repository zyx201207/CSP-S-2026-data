#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,n,m,d,qu,w[N],dp[500010],tot=0,head[N],ans[N];
int late[N];//late表示到i的最小时间 
struct station {
	int nt[30],top=0,w[30];
}st[500010]; 
struct ques {
	int x,y,id;
}que[N];
bool cmp(ques x,ques y) {
	return x.x<y.x;
}
signed main() {
	freopen("subway3.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		int k;cin>>k;
		for(int j=1;j<=k;j++) {
			int v,w;cin>>v>>w;
			st[v].nt[++st[v].top]=i;
			st[v].w[st[v].top]=w;
		}
	}

	for(int i=1;i<=qu;i++) {
		cin>>que[i].x>>que[i].y;
		que[i].id=i;
	}
	sort(que+1,que+qu+1,cmp);
	
	for(int k=1;k<=qu;k++) {
		if(que[k].x!=que[k-1].x) {
			queue<int> q;
			memset(dp,0x7f,sizeof dp);
			for(int i=1;i<=n;i++) late[i]=INT_MAX;
			dp[que[k].x]=0;
			q.push(que[k].x);
			for(int i=1;i<=m;i++) if(i!=que[i].x) q.push(i);
			for(int s=1;s<=10;s++)
				for(int i=1;i<=m;i++) {
					bool flag=0;
					q.pop();
					for(int j=1;j<=st[i].top;j++) {
						int to=st[i].nt[j],w=st[i].w[j];
						if(i==1||late[to]!=INT_MAX) flag=1;
						dp[i]=min(dp[i],late[to]+w);
						if(late[to]==INT_MAX) late[to]=min(late[to],dp[i]+w);
					}
					if(flag==0) q.push(i);
				}
		}
		ans[que[k].id]=abs(dp[que[k].x]-dp[que[k].y])+w[que[k].x]+w[que[k].y];
	}
	for(int i=1;i<=qu;i++) {
		cout<<ans[i]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2

0 3 7 20 2 
8 3 6 1 7 2 9 
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6 
2 3
*/

