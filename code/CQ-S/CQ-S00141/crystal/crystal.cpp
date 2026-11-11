#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int a[N];
vector<int>vec;
int n;
int f[N];
int cost[N];
int m;
template<typename Tp>struct Deque{
	Tp w[N<<1];
	int hh=N,tt=hh-1;
	inline int size(){return tt-hh+1;}
	inline Tp front(){return w[hh];}
	inline Tp back(){return w[tt];}
	inline void pop_front(){hh++;}
	inline void pop_back(){tt--;}
	inline void push_front(const Tp&__x){w[--hh]=__x;}
	inline void push_back(const Tp&__x){w[++tt]=__x;}
};
Deque<int>q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	f[1]=1;cost[1]=0;
	q.push_back(1);
	for(int i=2;i<=n;i++){
		cost[i]=cost[i-1]+f[i-1]*(a[i]-a[i-1]);
		f[i]=f[i-1]+1;
		q.push_back(i);
		if(cost[i-1]+f[i-1]*(a[i]-a[i-1])>m){	
			while(q.size()&&cost[i]>m){
				int x=q.front();q.pop_front();
				f[i]--;cost[i]-=(a[i]-a[x]);
			}
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++)maxn=max(maxn,f[i]);
	cout<<maxn;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
/*
time:  14:48
*/
