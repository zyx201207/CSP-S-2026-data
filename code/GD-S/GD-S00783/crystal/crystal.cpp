#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],s[N];
int binary_search(int x){
	int l=1,r=x,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		int len=x-mid+1;
		if(a[x]*len-(s[x]-s[mid-1])<=m){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >>m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int pos=binary_search(i);
		ans=max(ans,i-pos+1);
	}
	cout << ans;
} 
