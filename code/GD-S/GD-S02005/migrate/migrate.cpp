#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
int a[309];
bool is[309][309];
int dis[309][309];
struct node{
	int pos,cnt;
};
bool go(int s,int t){
	queue<node> q;
	q.push({s,0});
	int mn = 1e18,p = 0;
	while(q.size()){
		auto I = q.front();q.pop();
		int pos = I.pos,cnt = I.cnt;
//		cout<<pos<<" "<<cnt<<'\n';
		if(pos == t){
			if(p == 0) mn = cnt;
			if(cnt == mn) p++;
			if(p>2) return 0;
			continue;
		}
		for(int i = pos+1;i<=t;++i){
			if(a[i]-a[pos]>d) break;
			if(cnt+1>mn) break;
			q.push({i,cnt+1});
		}
	}
	return p == 2;
}
void work(){
	cin>>n>>d;
	for(int i = 1;i<=n;++i){
		cin>>a[i];
	}
	int ans = 0;
	for(int i = 1;i<=n;++i){
		for(int j = i+1;j<=n;++j){
			if(go(i,j)){
//				cout<<i<<" "<<j<<'\n';
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) work();
}
