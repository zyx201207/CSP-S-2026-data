#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
const ll M=1e18+5,A=1e12+5;
int n,ans;
ll m,a[N],d[N],cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i+=1){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i+=1){
		d[i]=a[i]-a[i-1];
	}
	for(int l=1,r=1;r<=n;l+=1,r=max(r,l)){
		cnt-=a[r]-a[l];
		while(cnt+1ll*(r-l+1)*d[r+1]<=m&&r<=n){
			cnt+=1ll*(r-l+1)*d[r+1];
			r+=1;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
