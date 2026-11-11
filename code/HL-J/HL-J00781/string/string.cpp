#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;cin>>n;
	vector<int>a;vector<char>c;
	for(int i=1;i<=n;i++){
		int a1;char c1;
		cin>>a1>>c1;
		a.push_back(a1);
		c.push_back(c1);
	}
	int l=0,r=n-1;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]<=a[r]){
				a[r]-=a[l];
				l++;
			}else{
				a[l]-=a[r];
				r--;
			}
		}
		else {
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
