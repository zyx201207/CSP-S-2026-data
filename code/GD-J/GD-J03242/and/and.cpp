#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,maxn,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<=n-m;i++){
		b=a[i];
		for(long long j=i;j<i+m;j++){
			b=a[j]&b;
		}
		if(b>maxn)maxn=b;
	}
	cout<<maxn;
	return 0;
}
