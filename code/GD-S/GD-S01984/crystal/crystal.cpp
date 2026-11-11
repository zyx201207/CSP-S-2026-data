#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[500005];
ll b[500005];
ll c[500005];
ll k;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	c[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i];
	}
	deque<ll>dq;
	dq.push_back(1);
	int ans=-1;
	ll sum=0;
	for(int i=2;i<=n;i++){
		dq.push_back(i);
		sum+=(dq.size()-1)*(c[i]-c[i-1]);
		while(sum>k){
			sum-=(c[dq.back()]-c[dq.front()]);
			dq.pop_front();
		}
		int cnt=dq.size();
		ans=cnt>ans?cnt:ans;
	}
	cout<<ans;
	return 0;
}


