#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
const int N=5e5+5;
ll a[N];
deque<ll>q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	q.push_front(a[1]);
	ll now=0,ans=0;
	for(int i=2;i<=n;i++){
		now+=(a[i]-q.back())*q.size();
		q.push_back(a[i]);
		while(now>m){
			now-=(a[i]-q.front());
			q.pop_front();
		}
		ans=max(ans,(ll)q.size());
	}
	printf("%lld",ans);
	return 0;
}
