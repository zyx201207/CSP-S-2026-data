#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10; 
int n,m,a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int id=1,sum=0;
	for(int i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-id);
		while(sum>m) sum-=a[i]-a[id],id++;
		ans=max(ans,i-id+1);
	}
	cout<<ans;
	return 0;
}
