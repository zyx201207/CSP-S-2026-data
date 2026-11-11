#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;
const int maxn = 5e5+5;
int n,m,ans,cnt;
long long now,cost;
long long a[maxn];
queue<long long>que; 
signed main(){
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
//	for(int i = 1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<'\n';
	que.push(a[1]),cnt++;
	now = a[1];
	ans = 1;
	for(int i = 2;i<=n;i++){
		//现在共有cnt个now,想新增的话代价为((a[i]-now)*cnt) 
		cost = (a[i]-now)*1ll*cnt;
//		cout<<cost<<"\n";
		if(cost<=m){
			m-=cost;
			que.push(a[i]);
			cnt++;
			now = a[i];
		}else{
			while(cost>m){
				m += (now-que.front());
				que.pop();
				cnt--;
				cost -= (a[i]-now);
			}
			que.push(a[i]);
			m-=cost;
			cnt++;
			now = a[i];
		}
		ans = max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
/*
考虑类似单调队列的思想，进行滑动窗口 
目前的队列里有：a_l,a_(l+1),..., ar
1.如果新的元素加入的代价仍小于现有的m，则加入，并令m减去对应代价 
2.如果新的元素加入的代价大于现有的m，弹出队头元素，并让m增加  

5 8
-3 -1 2 2 7
*/
