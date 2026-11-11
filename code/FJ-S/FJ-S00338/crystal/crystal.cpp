#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,num=0,ans=0;
int a[N];
queue <int> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		num++;
		m-=(q.size()*(a[i]-a[i-1]));
		while(m<0){
			int t=q.front();
			m+=(a[i]-t);
			q.pop();
			num--;
		}
		ans=max(ans,num);
		q.push(a[i]);
	}
	cout<<ans;
	return 0;
}
