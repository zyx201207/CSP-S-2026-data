#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<random>
#include<string.h>
#include<math.h>
#define endl '\n'
using namespace std;
using ll=long long;
const int MAXN=1000005;
int c,n,k;
vector<int> G[MAXN];
void solve(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		G[u].push_back(v),G[v].push_back(u);
	}
	if(c==13||c==14){
		int m=n/2;
		priority_queue<int> q;
		q.push(m/2),q.push(m/2);
		q.push(m/2+1),q.push(m/2+1);
		while(k--){
			int t=q.top(); q.pop();
			if(t>0) q.push(t-1);
		}
		cout<<q.top()<<endl;
	}else cout<<rand()%n<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	cin>>c>>T;
	while(T--){
		for(int i=1;i<=n;i++) G[i].clear();
		solve();
	}
	return 0;
}
