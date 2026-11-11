#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,sum,ans,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-j);
		while(sum>m){
			sum-=a[i]-a[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
