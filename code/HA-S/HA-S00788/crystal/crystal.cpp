#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500001],res,num,m,ans;
deque<int> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		if(!q.size()){
			q.push_front(a[i]);
			continue;
		}
		while(res+q.back()-a[i]>m){
			int u=q.back();
			q.pop_back();
			ans=max(num+1,ans);
			res-=num*(u-q.back());
			num--;
		}
		q.push_front(a[i]);
		res+=q.back()-a[i];
		num++;
	}
	ans=max(num+1,ans);
	cout<<ans;
}
