#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,len;
int a[500005],c,sum;
deque<int> dq;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ans=1;
	dq.push_back(1);
	for(int i=2;i<=n;i++){
		if(!dq.empty()){
			sum+=dq.size()*(a[i]-a[i-1]);
			while(!dq.empty()&&sum>m){
				sum-=(a[i]-a[dq.front()]);
				dq.pop_front();
			}
		}
		dq.push_back(i);
		len=dq.size();
		ans=max(ans,len);
	}
	cout<<ans;
}
