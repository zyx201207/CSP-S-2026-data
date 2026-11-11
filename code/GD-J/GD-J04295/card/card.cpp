#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5*1e5+10;
ll n,m;
ll a[N],t[N];
ll t1[N];
queue<ll>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	q.push(a[1]);
	t[a[1]]++;
	for(ll i=1;i<=n;i++){//一共n轮游戏 
		for(ll j=i;j<=n;j++){
			if(t[a[j]]==0){//如果牌堆里没有你手上这张牌，入队（放牌） 
				q.push(a[j]);
				t[a[j]]++;
			}else{//有这张牌，收走右边的牌之后入队
				while(!q.empty()){
					q.pop();
				}
				memset(t,0,sizeof(t));
				q.push(a[j]);
				t[a[j]]++;
			}
		}
		while(!q.empty()){//看一下这轮剩下的牌 (队列中的牌)并清空 
			t1[q.front()]++;
			q.pop();
		}
		memset(t,0,sizeof(t));//清空桶 
	}
	for(ll i=1;i<=m;i++){
		cout<<t1[i]<<" ";
	}
	return 0;
}
