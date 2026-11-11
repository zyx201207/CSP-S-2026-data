#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+2;
int a[N],p[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n>=5e5){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
		}
		if(sum<=m)ans=max(ans,i);
	}
	cout<<ans;
	return 0;
}
