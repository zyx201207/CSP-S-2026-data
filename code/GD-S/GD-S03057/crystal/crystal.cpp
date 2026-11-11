#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int n,m,sum,ans;
deque<int>q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		while(!q.empty()&&sum>m-(a[i]-a[i-1])*q.size())
		{
			sum-=a[i-1]-a[q.front()];
			q.pop_front();
		}
		q.push_back(i);
		sum+=(a[i]-a[i-1])*(q.size()-1);
		if(ans<q.size())
			ans=q.size();
	}
	cout<<ans<<'\n';
	return 0;
}

