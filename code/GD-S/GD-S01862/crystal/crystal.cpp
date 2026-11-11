#include<bits/stdc++.h>
using namespace std;
long long n,maxn=0,p[500005],mxx=0;
long long m,a[500005],sum=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<n; i++) {
		p[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		maxn=0;
		sum=0;
		for(int j=i;j<n;j++) {
			if(sum+p[j]*(j-i+1)<=m){
				sum+=p[j]*(j-i+1);
				maxn++;
			}
			else break;
		}
		mxx=max(maxn,mxx);
	}
	cout<<mxx+1;
	return 0;
}
