#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],n,m,ans,mind=0x3f3f3f3f3f3f3f3f,pos;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i+m-1<=n;i++){
		ll sum=a[i];
		for(int j=i;j<=i+m-1;j++) sum&=a[j];
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
