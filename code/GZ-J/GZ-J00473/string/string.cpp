//GZ-J00473 遵义市第四初级中学 陈昊然 
#include <bits/stdc++.h>
using namespace std;
struct S {
	char c;
	long long a;
};
long long n;
long long lon;
long long ans;
S s[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0; i<=n-1; i++) {
		cin>>s[i].a>>s[i].c;
		lon+=s[i].a;
	}
	long long lon_2=0;
	if(lon%2==0) lon_2=lon/2;
	else lon_2=lon/2+1;
	long long l=0,r=n-1;
	while(lon_2) {
		if(s[l].a==0) l++;
		else if(s[r].a==0) r--;
		long long mx=max(s[l].a,s[r].a);
		long long mn=min(s[l].a,s[r].a);
		if(s[l].c==s[r].c) {
			if(mx==s[l].a) {
				s[l].a-=s[r].a;
				r--;
			} else if(mx==s[r].a) {
				s[r].a-=s[l].a;
				l++;
			}
		} else {
			if(mx==s[l].a) {
				s[l].a-=s[r].a;
				r--;
			} else if(mx==s[r].a) {
				s[r].a-=s[l].a;
				l++;
			}
			ans+=mn;
		}
		lon_2-=mn;
		if(lon_2<=0) {
			break;
		}
	}
	cout<<ans;
	return 0;
}

