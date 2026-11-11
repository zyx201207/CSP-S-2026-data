#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
long long n,a[N],cnt;
char x;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>x;
		s+=x;
	}
	s=" "+s;
	while(l<r) {
		if(s[l]!=s[r]) {
			if(a[l]<a[r]) cnt+=a[l],a[r]-=a[l],l++;
			else cnt+=a[r],a[l]-=a[r],r--;
		} else {
			if(a[l]<a[r]) a[r]-=a[l],l++;
			else a[l]-=a[r],r--;
		}
	}
	cout<<cnt;
	return 0;
}
