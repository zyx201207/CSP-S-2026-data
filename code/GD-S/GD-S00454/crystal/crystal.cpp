#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=1;
	for(int i=1;i<=n;i++){
		int sum=1;
		int lst=m;
		for(int j=i-1;j>=1;j--){
			if(lst>=(a[i]-a[j])){
				sum++;
				lst-=(a[i]-a[j]);
			}else{
				break;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
