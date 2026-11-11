#include <bits/stdc++.h>
using namespace std;
#define int long long
char c[211111];
int n,l,r,a[211111],ans;
string s1,s2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	l=1,r=n;
	while (l<r){
		if (c[l]!=c[r]){
			if (a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}else if (a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
			    l++;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}else{
			if (a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if (a[l]<a[r]){
				a[r]-=a[l];
			    l++;
			}else{
				l++;
				r--;
			}
		} 
	}
	cout << ans;
	return 0;
}
