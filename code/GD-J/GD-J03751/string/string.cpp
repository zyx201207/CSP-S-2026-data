#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[20100];
char s[20100];
int cnt;
signed main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i]>>s[i];
	}
    for (int i=1,j=n;i<j;) {
    	if (s[i]!=s[j]) {
    		cnt+=min(a[i],a[j]);
		}
		a[i]-=min(a[i],a[j]);
    	a[j]-=min(a[i],a[j]);
    	if (a[i]==0) {
    		i++;
		}
		if (a[j]==0) {
			j--;
		}
		continue;
	}
	cout<<cnt;
	return 0; 
	fclose(stdin);
	fclose(stdout);
}
