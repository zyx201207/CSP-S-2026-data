#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],cnt=0,maxn=0,s;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll r=2,l=1;
	s=m;
	while(r<n){
		while(m<(a[r]-a[r-1])*(r-l)){
			m=min(m+a[r]-a[l],s);
			l++;
			cnt--;
		}
		m-=(a[r]-a[r-1])*(r-l);
		cnt++;
		maxn=max(maxn,cnt);
		r++;
	}
	cout<<maxn;
    return 0;
}
