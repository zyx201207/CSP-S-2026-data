#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n,ans;
ll m,a[N];
__int128 sum;
deque <int> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		q.push_back(i);
		sum+=(q.size()-1)*(a[i]-a[i-1]);
		while(!q.empty() && sum>m){
			sum-=(a[i]-a[q.front()]);
			q.pop_front();
		}
		ans=max(ans,(int)q.size());
	}
	cout<<ans;
	return 0;
}
