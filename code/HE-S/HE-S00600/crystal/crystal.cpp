#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,ans,a[N];
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1,sum=0;i<=n;i++){
		sum+=a[i];
		while(((i-j+1)*a[i])-sum>m) sum-=a[j],j++;
		ans=max(ans,(i-j+1));
	}
	cout<<ans;
	return 0;
}
