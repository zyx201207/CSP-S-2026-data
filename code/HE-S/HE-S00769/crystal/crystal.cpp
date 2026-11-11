#include<bits/stdc++.h>
using namespace std;
int a[100000],n;
long long m;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	int p=1;
	sort(a,a+n);
	long long maxx=-1000000;
	for(long long i=n;i>0;i--){
		long long y=m;
		for(long long j=i-1;j>0;j--){
			y=y-(a[i]-a[j]);
			if(y<0){
				continue;
			}
			p++;
		}
		if(maxx<p){
			maxx=p;
		}
		p=1;
	}
	cout<<maxx;
	return 0;
}
