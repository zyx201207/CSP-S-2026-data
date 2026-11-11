#include <bits/stdc++.h>
using namespace std;
int b[20005];
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string a[20005];
	string s;
	for (int i=0;i<n;i++) {
		cin>>b[i];
		cin>>a[i];
		for (int j=1;j<=b[i];j++) {
			s+=a[i];
		}
		}
	int ss=s.size();
	int k=ss,l=0;
	if (ss==1) {
		cout<<"0";
		return 0;
		}
	while (l<=k) {
		if (s[l]!=s[k]) {
			cout<<"0";
			}
			k--;
			l++;
			}
	return 0;
}
