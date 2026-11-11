#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],k,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	k=abs(a[2]-a[1]);
	while (m>=k){
		m-=k;
		k+=k;
		ans++;
		if (ans>n){
			ans=n;break;
		}
	}
	cout<<ans;
	return 0;
}
