#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
int n,idx,ans;
ll m,sum[N],a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m,idx=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1),idx=1;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		while(a[i]*(i-idx+1)-sum[i]+sum[idx-1]>m) idx++;
		ans=max(ans,i-idx+1);
	}
	cout<<ans;
	return 0;
}
