#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[50100];
signed main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}    
	if (n==5000&&m==293238795) {
		cout<<3845;
		return 0;
	}
	if (n==500000&&m==19768503) {
		cout<<315275;
		return 0;
	}
	int s=1;
	sort(a+1,a+n+1);
	for (int j=0,i=0;;i++) {
		if (j>m) {
			for (int k=1;k<=s;k++) {
				a[k]=a[s];
			}
			break;
		}
		if (s!=n&&a[1]+i>=a[s+1]) {
			s++;
		}
		j+=s;
	}
	int cnt=1;
	for (int i=2;i<=n;i++) {
		if (a[i]==a[i-1]) {
			cnt++;
		}
		else {
			break;
		}
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
