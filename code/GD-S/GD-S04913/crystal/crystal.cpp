#include<bits/stdc++.h>
using namespace std;
long long n,m,last=1,cnt,ans;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		cnt+=(i-last)*(a[i]-a[i-1]);
		while(cnt>m){
			cnt-=a[i]-a[last];
			last++;
		}
		ans=max(ans,i-last+1);
	}
	cout<<ans;
	return 0;
}
