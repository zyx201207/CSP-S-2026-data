#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100001];
long long h[100001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	h[1]=9223372036854775807;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ma=-99999;
	for(int i=1;i<=n-m;i++){
		for(int j=i;j<=i+m;j++){
			h[i]=(a[j]&h[i]);
		}	
	}
	for(int i=1;i<=n-m;i++){
		ma=max(ma,h[i]);
	}
	cout<<ma;
	return 0;
}
