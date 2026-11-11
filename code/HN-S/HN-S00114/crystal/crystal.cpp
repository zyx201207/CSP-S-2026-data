#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int pre;
int cnt,ans;
int a[N];
priority_queue<int,vector<int>,greater<int>> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		int cost=a[i]*cnt-pre;
//		cout<<"cost: "<<cost<<'\n';
		cnt++;
		q.push(a[i]);
		pre+=a[i];
		while(!q.empty()&&m<cost){
//			cout<<"poped "<<q.top()<<'\n';
			cnt--;
//			cout<<"regot "<<i<<' '<<a[i]<<'\n';
			cost-=a[i]-q.top();
			pre-=q.top();
			q.pop();
		}
//		cout<<"pre: "<<pre<<'\n';
		ans=max(ans,cnt);
//		cout<<"cnt: "<<cnt<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
---
3

5 8
-3 -1 2 2 7
-----
4
*/
