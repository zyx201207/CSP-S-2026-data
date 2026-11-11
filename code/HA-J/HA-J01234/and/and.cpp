#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long sum;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(a[i]|a[j]>sum) sum=a[i]|a[j];
		}
	}
	cout<<sum;
	return 0;
}
