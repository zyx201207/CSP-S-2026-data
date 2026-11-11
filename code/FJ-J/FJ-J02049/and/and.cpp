#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if (m==1){
		long long maxx=INT_MIN;
		for (long long i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
		return 0;
	}
	else if (m==2){
		long long maxx=INT_MIN;
		for (long long i=1;i<=n;i++){
			for (long long j=i+1;j<=n;j++){
				maxx=max(a[i]&a[j],maxx);
			}
		}
		cout<<maxx;
		return 0;
	}
	else if (m==n){
		long long maxx=INT_MIN;
		for (long long i=1;i<=n-1;i++){
			a[i]&=a[i+1];
			a[i+1]=a[i];
		}
		cout<<a[n];
		return 0;
	}
	return 0;
}
