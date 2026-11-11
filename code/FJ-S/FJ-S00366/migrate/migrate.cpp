#include<bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;

const ll N=2e6+10;
ll c,t;
ll n,d;
ll a[N];

void solveB() {
	while(t--) {
		memset(a,0,sizeof a);
		cin>>n>>d;
		for(ll i=1; i<=n; i++)cin>>a[i];
		ll ids=0;
		for(ll i=1; i<=n; i++) {
			if(a[i]-a[1]>d) {
				ids=i;
				break;
			}
		}
		ll ans=0;
		for(ll i=ids; i<=n; i++) {
			if(a[i]-a[ids-1]<=d&&a[i]-a[ids-2]<=d) {
//				cout<<i<<endl;
				ans++;
			} else {
				break;
			}
		}
		cout<<ans<<endl;
	}
}
void solveA() {
	while(t--) {
		memset(a,0,sizeof a);
		cin>>n>>d;
		for(ll i=1; i<=n; i++) {
			cin>>a[i];
		}
		ll cha=a[2]-a[1];
		if(cha>d) {
			cout<<0<<endl;
			continue;
		}
		ll p=d/cha;
//		cout<<"一次飞过岛屿数量："<<p<<endl;
		ll ids=p+2;
//		cout<<"需要两次的第一座岛屿："<<ids<<endl;
		ll num=n-ids+1;
//		cout<<"一共有多少座岛屿需要两次及以上："<<num<<endl;
		ll ans=0;
//		cout<<"最多到第几座岛不行:"<<n-p<<endl;
		for(ll i=1; i<=n-p; i++) {
//			p-1个有+1个无
			ll shu=n-i-p;
//			cout<<"第"<<i<<"座有多少座岛屿>=2次："<<shu<<" "<<p-1<<endl;
//			cout<<i<<" "<<shu<<endl;
			if(shu>=p-1) {
				ans++;
			}
			if(shu<p-1)break;

		}
		cout<<ans<<endl;
	}
}
void baoli() {
	while(t--) {
		memset(a,0,sizeof a);
		cin>>n>>d;
		int ids=-1;
		for(ll i=1; i<=n; i++) {
			cin>>a[i];
			if(a[i]-a[i-1]>d) {
				ids=i-1;
				break;
			}
		}
		int ans=0;
		for(int i=1; i<=n; i++) {
			priority_queue<P,vector<P>,greater<P>>q;
			q.push({0,i});
			int b[305],c[305];
			while(!q.empty()) {
				int fly=q.top().first;
				int now=q.top().second;
				q.pop();
				if(b[now]==0)b[now]=fly;
				else {
					if(fly==b[now])c[now]++;
				}
				for(int i=now+1; i<=n; i++) {
					if(a[i]-a[now]<=d) {
						q.push({fly+1,i});
					}
				}
			}
			for(int j=i; j<=n; j++) {
				if(c[j]==2)ans++;
			}
//			for(int j=1;j<=n;j++){
//				cout<<b[j]<<" ";
//			}
//			cout<<endl;
//			for(int j=1;j<=n;j++){
//				cout<<c[j]<<" ";
//			}
//			cout<<endl;
//			cout<<ans<<endl;
//		}
		}
		cout<<ans<<endl;
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c>=13&&c<=14) {
		solveB();
	} else if(c>=11&&c<=12) {
		solveA();
	} else {
		baoli();
	}
	return 0;
}
/*
13 1
5 2
1 2 3 4 5

0 1
10 3
1 2 3 4 5 6 7 8 9 10

4
8

0 1
5 3
-2 -1 0 1 2
*/

