#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int a[N],n,m,sum,ans;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=0;i<=n;i++){
		sum+=a[i];
		while(a[i]*(i-j)>m+sum) sum-=a[++j]; 
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
}
