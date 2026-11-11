#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int t=1,cnt=0,cnt2=0;
	for(int i=1;i<=n;i++){
		cnt+=(i-t)*(a[i]-a[i-1]);
		cnt2++;
		while(cnt>m&&t<=n){
			cnt-=a[i]-a[t++];
			cnt2--;
		}
		ans=max(ans,cnt2);
	}
	cout<<ans;
	return 0;
}
