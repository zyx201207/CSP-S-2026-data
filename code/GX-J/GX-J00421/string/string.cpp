#include<bits/stdc++.h>
using namespace std;
long long n,a1,ans=0,cnt=0;
long long a[214514];
string b,b1;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a1>>b1;
		if(i>0&&b1[0]==b[ans]) {
			a[ans]+=a1;
		} else {
			ans++;
			a[ans]=a1;
			b[ans]=b1[0];
		}
	}
	int l=1,r=n;
	while(l<r) {
		if(b[l]==b[r]) {
			if(a[l]>=a[r]) {
				a[l]-=a[r];
				r--;
				if(a[l]==0) {
					l++;
				}
			} else {
				l++;
			}
		} else {
			if(a[l]>=a[r]) {
				a[l]-=a[r];
				cnt+=a[r];
				r--;
				if(a[l]==0) {
					l++;
				}
			} else {
				cnt+=a[l];
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
