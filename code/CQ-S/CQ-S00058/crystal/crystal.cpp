#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+100;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int t=m,now=n;
	int ans=1;
	for(int i=n;i>=1;i--){
		while(a[i]-a[now]<=t&&now!=0){
			t-=a[i]-a[now];
			now--;
		}
		ans=max(ans,i-now);
		t+=(i-now-1)*(a[i]-a[i-1]);
	}
	cout<<ans;
}

