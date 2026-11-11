#include<bits/stdc++.h>
using namespace std;
const int N=1e9+5,M=2*1e5+5;
long long a[M];
char s[M],ans[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long cnt=1,sum=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>s[i];
		cnt+=a[i];
		for(int j=1; j<=a[i]; j++) {
			ans[j]=s[i];

		}
	}

	int l=1,r=cnt;
	while(l!=r&&l<=r) {
		if(ans[l]!=ans[r]) {
			sum++;
			l++,r--;
		} else {
			l++,r--;
		}

	}
	cout<<sum;
	return 0;
}
