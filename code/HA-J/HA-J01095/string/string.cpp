#include<bits/stdc++.h>
using namespace std;
long long n,a[500001],cnt=0;
char c[500001];
int st,e;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	st=1,e=n;
	while(st<e) {
		if(c[st]==c[e]) {
			if(a[st]>a[e]) {

				a[st]-=a[e];
				e--;
			} else if(a[st]<a[e]) {

				a[e]-=a[st];
				st++;
			} else {
				st++;
				e--;
			}

		}   else  {
			if(a[st]>a[e]) {
				cnt+=a[e];
				a[st]-=a[e];
				e--;

			} else if(a[st]<a[e]) {
				cnt+=a[st];
				a[e]-=a[st];
				st++;

			} else {
				cnt+=a[st];
				st++;
				e--;
			}
		}


	}
	cout<<cnt;
	return 0;
}
