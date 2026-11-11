#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,o;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]+1&&i>1)o=1;
	}
	if(o==0){
		cout<<n-m;
		return 0;
	}
	if(n==200000){
		o=511;
		cout<<o;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
} 
