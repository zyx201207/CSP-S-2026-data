#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
queue <int> q;
int n,m,tot,ans;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	q.push(1);
	tot=0;
	ans=1;
	for(int i=2;i<=n;i++){
		tot+=q.size()*(a[i]-a[i-1]);
		while(!q.empty()&&tot>m){
			tot-=a[i]-a[q.front()];
			q.pop();
		} 
		q.push(i);
		ans=max(ans,(int)q.size());
//		cout<<ans<<' '<<tot<<'\n';
	}
	cout<<ans<<'\n';
}
//记得对拍 
//14：49 通过所有大洋里，开始对拍 
