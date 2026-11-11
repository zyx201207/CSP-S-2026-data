#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in""r",stdin);
	freopen("string.out""w",stdout);
	int n,b=0;
	cin>>n;
	int a[n];
	string s[n],sum[n+n];
	for(int i=0;i<=n-1;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=0;i<=n-1;i++){
		cout<<a[i]<<s[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=a[i];j++){
			sum[i]=s[i];
			b++;
		}
	}
	for(int i=0;i<=n-1;i++){
		cout<<sum[i];
	}
	return 0;
} 
