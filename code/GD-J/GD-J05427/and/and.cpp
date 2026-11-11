#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
int m;
long long maxx=-1;
long long sum=0;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		sum=a[i]&&a[i-1];
		maxx=max(sum,maxx);
		maxx++;
	}
	cout<<maxx;
    return 0;
}
