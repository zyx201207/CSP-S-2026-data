#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e5+7;
int n,m;
int a[N],s[N];
int32_t main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=1;
	int ans=0;
	while(r<=n){
		int sum=0;
		sum=((r-l+1)*a[r]-(s[r]-s[l-1]));
		if(sum>m){
			l++;
		}else{
			if(r-l+1>ans){
				ans=r-l+1;
			}
			r++;
		}
	}
	cout<<ans;
	return 0;
}
