#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,tot=1,sum,ans=1;
int a[N],b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum+=(i-tot)*(a[i]-a[i-1]);
		while(sum>k){
			sum-=a[i]-a[tot];
			tot++;
		}
		ans=max(ans,i-tot+1);
	}
	cout<<ans;
	return 0;
}
