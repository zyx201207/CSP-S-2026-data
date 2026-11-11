#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		for(int i=n;i>=1;i++){
			if((a[1]+a[i])*n/2<=m){
				cout<<i;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
	}for(int j=n-1;j>=1;j--){
		for(int i=1;i+j<=n;i++){
			if(s[i+j]-s[i]-(i-1)*(a[i+j]-a[i])<=m){
				cout<<j+1;
				return 0;
			}
		}
	}
	return 0;
}
