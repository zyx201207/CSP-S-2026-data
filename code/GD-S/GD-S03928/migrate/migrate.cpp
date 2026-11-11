#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
struct node {
	ll dis,x,id,f;
	node() {}
	node(ll _dis,ll _x,ll _id,ll _f): dis(_dis), x(_x), id(_id), f(_f) {}
};
ll c,t,n,x[N],d,p[N],ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("migrate3.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) 
			cin>>x[i];
//		for(int i=1;i<=n;i++) {
//			for(int j=1;j<=n;j++) {
//				if(abs(x[i]-x[j])<=d)
//					cout<<"1 ";
//				else cout<<"0 ";
//			}cout<<'\n';
//		}
		for(int i=1;i<=n;i++) {
			p[0]++;
			deque<node> q;
			q.push_back(node(0,x[i],i,1));
			for(int j=i+1;j<=n;j++) {
				if(j==5)
					int _t=0;
				while(!q.empty()&&abs(q.front().x-x[j])>d) {
					p[q.front().dis]-=q.front().f;
					q.pop_front();
				}
				if(q.empty())
					break;
				node u;
				u.id=j;
				u.x=x[j];
				u.f=p[q.front().dis];
				u.dis=q.front().dis+1;
//				while(!q.empty()&&q.back().dis>u.dis)
//					q.pop_back();
				if(p[q.front().dis]==2)
					ans++;
				q.push_back(u);
				p[u.dis]+=u.f;
			}
			while(!q.empty()) {
				p[q.front().dis]-=q.front().f;
				q.pop_front();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
