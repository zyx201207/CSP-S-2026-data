#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+22;
int n,m,a[N],ans;
deque <int> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	q.push_back(a[1]);
	for(int i=2;i<=n;i++){
		while(!q.empty() && (a[i]-q.back())*q.size()>m){
			m+=(q.back()-q.front());
			q.pop_front();
		}
		if(!q.empty()) m-=(a[i]-q.back())*q.size();
		q.push_back(a[i]);
		ans=max(ans,(int)q.size());
	}
	printf("%lld",ans);
}
