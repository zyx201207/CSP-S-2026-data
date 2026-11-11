#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int k=n;k>=2;k--){
		for(int l=1;l<=n;l++){
			if(l+k-1>n){
				break;
			}
			int r=l+k-1;
			if(b[r]-b[l-1]-(a[r]-a[l-1])*(l-1)<=m){
				cout<<k;
				return 0;
			}
		}
	}
	return 0;
} 
