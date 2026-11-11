#include<bits/stdc++.h>
using namespace std;
int n,a,b;
long long q[200010],ans;
char c[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>q[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r) {
		if(c[l]==c[r]) {
			if(q[l]>=q[r]) {
				q[l]-=q[r];
				q[r]=0;
				r--;

				if(q[l]==0) {
					l++;
				}
			} else if(q[l]<q[r]) {
				q[r]-=q[l];
				q[l]=0;
				l++;

			}
		} else if(c[l]!=c[r]) {
			if(q[l]>=q[r]) {
				ans+=q[r];
				q[l]-=q[r];
				q[r]=0;
				r--;

				if(q[l]==0) {
					l++;
				}
			} else if(q[l]<q[r]) {
				ans+=q[l];
				q[r]-=q[l];
				q[l]=0;
				l++;

			}
		}
	}
	cout<<ans;
	return 0;
}
