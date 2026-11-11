#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=2e5+10;
int n,m,a[N],ans=0;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
