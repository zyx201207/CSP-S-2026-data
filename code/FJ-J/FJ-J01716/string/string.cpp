#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
long long n,cnt=0,l;
long long a[N];
string c;
string s,ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1)cout<<"0";
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		cin>>c[i];
		for(int j=1; j<=a[i]; j++) {
			s[j]+=c[i];
			l=j;
		}
	}
	for(int i=0; i<l; i++) {
		if(s[i]==s[l+1-i]) cnt=0;
		else {
			while(l>l/2) {
				if(s[i]!=s[l]) {
					cnt+=2;
				}
				l--;
			}
			cout<<cnt;
			return 0;
		}
	}
	cout<<cnt;
	return 0;
}

