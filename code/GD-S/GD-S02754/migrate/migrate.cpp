#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,step;
};
const int N=2e6+10;
long long a[N];
long long b[N];
long long n,d,cnt[N],mn[N];
void solve1(){
	if(a[n]-a[1]<=d||n<=3||a[3]-a[1]>d){
		cout<<"0\n";
		return;
	}
	int mx=0;
	for(int i=2;i<=n;i++){
		if(a[i]-a[1]<=d)mx=i-1;
		else break;
	}
	long long ans=n-mx*2+1;
	cout<<ans<<"\n";
}
void bfs(int u){
	memset(cnt,0,sizeof cnt);
	memset(mn,0,sizeof mn);
	queue<node>q;
	q.push({u,0});
	while(!q.empty()){
		int now=q.front().x,step=q.front().step;
		q.pop();
		if(mn[now]!=0&&step>mn[now])continue;
		if(now!=u&&mn[now]==0)mn[now]=step;
		if(mn[now]==step)cnt[now]++;
		for(int i=now+1;i<=n;i++){
			if(a[i]-a[now]<=d)q.push({i,step+1});
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;cin>>c;
	int T;cin>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			solve1();
			continue;
		}
		if(a[n]-a[1]<=d||n<=3){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
