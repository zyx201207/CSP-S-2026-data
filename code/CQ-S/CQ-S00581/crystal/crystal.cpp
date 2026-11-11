#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int cnt=1;
int ans,sum;
int a[500005];
priority_queue<int,vector<int>,greater<int> > pq;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=1,sum=0;
	sort(a+1,a+n+1);
	pq.push(a[1]);
	for(int i=2;i<=n;i++){
		int tp=cnt*(a[i]-a[i-1]);
		sum=sum+tp;
		while(sum>m){
			int g=pq.top();
			pq.pop();
			sum-=(a[i]-g);
			cnt--;
		}
		cnt++;
		pq.push(a[i]);
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
