#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
long long c[500005];
long long kk(int j){
	long long ans=0;
	
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=i+b[i-1];
	}
	long long cha=a[2]-a[1];
	for(int i=1;i<=n;i++){
		c[i]=cha*b[i];
		if(c[i]>m){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
