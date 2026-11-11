#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
ll a[N];
ll ans[N];
ll vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i ++){
		cin>>a[i];
	}
	
	int cnt = 1; //计数器  
	queue <int > q;
	//处理过程  队列先进先出 
	while(cnt <= n){
		for(int i = cnt ; i <= n ; i ++){
			q.push(a[i]);
			if(vis[a[i]] == 1){
				for(int j = 1; j <= i - 1 ; j ++){
					int t = q.front();
					q.pop();
					vis[t] = 0;
				}
			}
			vis[a[i]] = 1;
		}
		while(!q.empty()){
			int t = q.front();
			q.pop();
			ans[t] ++;
			vis[t] = 0;
		}
		cnt++;
	}
	//输出 
	for(int i = 1 ; i <= m ; i ++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
