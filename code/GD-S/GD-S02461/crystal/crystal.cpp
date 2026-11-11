#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+15;
ll m;
int n,ans;
ll a[N],s[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;++i)s[i]=s[i-1]+a[i];
	int l = 1;
	for(int i = 1;i <= n;++i){
		while(a[i]*(i-l+1)>s[i]-s[l-1]+m)++l;
		ans = max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
} 
