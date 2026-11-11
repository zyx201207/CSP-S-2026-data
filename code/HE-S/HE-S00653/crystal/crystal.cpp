#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans[500005],need[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);  

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans[1]=ans[0]=1;need[1]=0;
	for(int now=2;now<=n;now++){
		int add=ans[now-1]*(a[now]-a[now-1]);
		need[now]=need[now-1]+add;
		ans[now]=ans[now-1]+1; 
			int begine=now-ans[now-1];
		while(need[now]>m){
			need[now]-=(a[now]-a[begine]);
			ans[now]--;begine++;
		}
		ans[0]=max(ans[0],ans[now]);
	}
	cout<<ans[0];
}
