#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1e9;
long long a[200030],b[200030],c[200030];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<maxn;
		return 0;
	}
	maxn=-1e9;
	for(long long i=1;i<n;i++){
		for(long long j=i;j<=n;j++){
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout<<maxn;
	return 0;
} 
