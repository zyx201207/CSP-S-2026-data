#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000086];
signed main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=a[n];
	for(int i=n;i>=1;i--){
		if(m>0){
			ans&=a[i];
		}
		m--;
	}
	cout<<ans;
	   return 0;
}

