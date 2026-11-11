#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;

int n,m;
int a[N];


int r;
int b[N];

int fd(int k) {
	for(int i=1;i<=r;i++) {
		if(b[i] == k) {
			return i;
		}
	}
	return -1;
}

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	int ans=0;
	for(int j=1;j<=m;j++) {
		r=0;
		for(int i=j;i<=n;i++) {
			int k=a[i];
			int f=fd(k);
			if(f == -1) {
				b[++r] = k;
			}
			else {
				r = f;
				b[r] = k;
			}
		}
		if(fd(j) != -1) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
