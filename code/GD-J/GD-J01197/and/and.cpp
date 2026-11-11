#include<bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxn=0;
	cin>>n>>m;
	long long c[10000];
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;i<j;i++){
			maxn=max(maxn,(c[i] & c[j]));}}
	cout<<maxn;
	return 0;
}
