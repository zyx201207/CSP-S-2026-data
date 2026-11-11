#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],l,r,ans;
char s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	l=1,r=n;
	while(l<=r){
		if(s[l]!=s[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				ans+=a[r];
				l++,r--;
			}else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				l++,r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
