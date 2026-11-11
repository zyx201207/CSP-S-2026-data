#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long maxn=0;
	for(long long i=0;i<n;i++){
		if(a[i]>maxn)
			maxn=a[i];
	}
	cout<<maxn;
	return 0;
} 
