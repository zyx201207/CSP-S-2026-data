#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int ans,n,num[N],a[N];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>num[i];
		char c;
		cin>>c;
		a[i]=c-'a';
	}
	int l=1,r=n;
	while(l<r) {
		if(a[l]==a[r]) {
			if(num[l]==num[r]) {
				l++;
				r--;
				continue;
			}
			else if(num[l]<num[r]) {
				num[r]-=num[l];
				l++;
				continue;
			}
			else {
				num[l]-=num[r];
				r--;
				continue;
			}
		}
		else {
			if(num[l]==num[r]) {
				ans+=num[r];
				l++;
				r--;
				continue;
			}
			else if(num[l]<num[r]) {
				ans+=num[l];
				num[r]-=num[l];
				l++;
				continue;
			}
			else {
				ans+=num[r];
				num[l]-=num[r];
				r--;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
