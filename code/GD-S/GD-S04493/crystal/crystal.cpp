#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[114514],b[114514];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int ans=1;
	for(ll i=n;i>=1;i--){
		if(m>=b[i]){
			cout<<i;
			return 0;
		}
	}
	cout<<1;
	return 0;
}
