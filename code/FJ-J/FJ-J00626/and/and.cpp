#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	long long max=INT_MIN;
	if(m==2) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				int f=a[i]&a[j];
				if(f>max) {
					max=f;
				}
			}
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>max){
				max=a[i];
			}
		}
	}
	if(m==n){
		int f=a[1];
		for(int i=2;i<=n;i++){
			f=f&a[i];
		}
		max=f;
	}
	cout<<max;
	return 0;
}
