#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<n;j++){
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout<<maxn;
	return 0;
}
