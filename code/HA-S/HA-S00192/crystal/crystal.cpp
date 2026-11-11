#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int n,m;
int ans;
int k;
queue<int> q;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
//		cout<<a[i]<<" ";
		if(i!=1)
			k+=(a[i]-a[i-1])*q.size();
		while(q.size()&&k>m) {
			k-=a[i]-a[q.front()];
			q.pop();
		}
		q.push(i);
		ans=max(ans,(int)q.size());
	}
	cout<<ans;
	return 0;
}
/*
q:1,k=0
q:2,k=0
q:2 3,k=24

*/
