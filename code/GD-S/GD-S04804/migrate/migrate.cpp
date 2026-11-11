#include<bits/stdc++.h>
#define pii pair<int,int>
#define pli pair<long long,int>
using namespace std;
const int maxn = 2e6+5;
const int inf = 1e9+5;
int c,t,n,d,sum;
long long a[maxn];
bool tot[maxn];
bool inq[maxn];
int dp[5005][5005];
int main(){
//	freopen("migrate3.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum = 0;
		cin>>n>>d;
		for(int i = 1;i<=n;i++)cin>>a[i];
		for(int i = 1;i<=n;i++)for(int j = 1;j<=n;j++)dp[i][j] = inf;
		for(int i = 1;i<=n;i++){
//			cout<<i<<": \n";
			queue<int>q;
			queue<pii>tmp;
			//可更新j的编号队列以及临时队列 
			priority_queue<pli,vector<pli>,greater<pli>>que;//值，编号 
			for(int j = i;j<=n;j++)inq[j] = 0,tot[j] = 0;//是否在队列以及到达j的最短径个数 
			q.push(i),inq[i] = 1,tot[i] = 1;
			dp[i][i] = 0,que.push({0,i});
			for(int j = i+1,minn,cnt=0;j<=n;j++){
//				if(a[j]-a[j-1]>d)break;
//				cout<<j<<": "<<a[j]<<" "<<q.front()<<" "<<d<<":\n";
				while(q.size()&&(a[j]-a[q.front()])>d){
					inq[q.front()] = 0;
//					cout<<q.front()<<" "<<a[q.front()]<<'\n';
					q.pop();
				}
//				cout<<"out\n";
				while(que.size()&&inq[que.top().second]==0)que.pop();
				minn = que.top().first,cnt = 0;
//				cout<<"minn:"<<minn<<'\n';
				while(que.size()&&que.top().first==minn){
				 	tmp.push(que.top());
				 	cnt += tot[que.top().second];
					que.pop();
					if(cnt>2)break;
				}
				while(tmp.size())que.push(tmp.front()),tmp.pop();
				dp[i][j] = minn+1;
//				cout<<dp[i][j]<<" "<<cnt<<'\n';
				tot[j] = cnt;
				if(cnt==2)sum++;
				q.push(j),inq[j] = 1;
				que.push({dp[i][j],j});
			}
		}
		cout<<sum<<'\n';
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
8 3
0 1 2 4 8 10 11 13

0 3
6 3
0 1 2 3 4 7
8 3
0 1 2 4 8 10 11 13
1 3
0
*/
