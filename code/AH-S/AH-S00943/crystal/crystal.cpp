#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,l,ans=1;
ll m,a[500005],now;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	l=1;
	for(int i=2;i<=n;i++){
		now+=(i-l)*(a[i]-a[i-1]);
		while(now>m){
			now-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

