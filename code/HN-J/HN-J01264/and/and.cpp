#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N];
long long maxn=0;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(m==n) {
		int cnt=a[1];
		for(int i=2; i<=n; i++) {
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	if(m+1==n) {
		maxn=0;
		for(int i=1; i<=n; i++) {
			int cnt,vis=1;
			for(int j=1; j<=n; j++) {
				if(j!=i) {
					if(vis==1) {
						vis=0;
						cnt=a[j];
					} else {
						cnt=(cnt&a[j]);
					}
				}
				if(cnt>maxn){
					maxn=cnt;
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==1) {
		long long maxn=0;
		for(int i=1; i<=n; i++) {
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2) {
		int maxn=0;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(maxn<(a[i]&a[j])){
					maxn=a[i]&a[j];
				}

			}
		}
		cout<<maxn;
		return 0;
	}
	
}
