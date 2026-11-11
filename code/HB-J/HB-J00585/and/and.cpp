#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxn=0;
	cin>>n>>m;
	if(m==1){
		for(long long i=1;i<=n;i++){
			long long a;
			cin>>a;
			maxn=max(maxn,a);
		}
	}
	else if(m==n){
		long long a;
		cin>>a;
		maxn=a;
		for(long long i=1;i<n;i++){
			long long b;
			cin>>b;
			maxn=maxn&b;
		}
	}
	else if(m==2){
		long long a[2026];
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
	}
	else{
		long long a[2026]={},mmm=n-1;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		maxn=a[n];
		for(long long i=m-1;i>=1;i--){
			maxn=maxn&a[m];
			mmm--;
		}
	}
	cout<<maxn;
	return 0;
}
