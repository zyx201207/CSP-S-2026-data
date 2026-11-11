#include<bits/stdc++.h>
using namespace std;
long long n,num[255555],ans;
char c[255555];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)cin>>num[i]>>c[i];
	int l=1,r=n;
	while(l<r) {
		if(c[l]==c[r]) {
			if(num[l]>=num[r]) {
				num[l]-=num[r];
				r--;
			} else {
				num[r]-=num[l];
				l++;
			}
		} else {
			if(num[l]>=num[r]) {
				num[l]-=num[r];
				ans+=num[r];
				r--;
			} else {
				num[r]-=num[l];
				ans+=num[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
