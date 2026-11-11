#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 1000005
int n,m;
int a[maxn];
priority_queue<int,vector<int>,greater<int> >q; 
int ans;
int ct=0;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n==1){
		cout << 1 << '\n';
	}else{
		sort(a+1,a+n+1);
		int mx=a[1];
		q.push(a[1]);
		for(int i = 2;i <= n;i++){
			mx=a[i];
			while(!q.empty()&&ct+q.size()*(a[i]-a[i-1])>m){
				ct-=a[i-1]-q.top();
				q.pop();
			}
			if(ct+q.size()*(a[i]-a[i-1])<=m){
				ct=ct+q.size()*(a[i]-a[i-1]);
				q.push(a[i]);
				ans=max(ans,(int)q.size());
			}
		}
	}
	cout << ans << '\n';
	return 0;
} 
