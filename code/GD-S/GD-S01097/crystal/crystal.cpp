#include<bits/stdc++.h>
using namespace std;
long long a[50010],s[50010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			s[i]=a[i]-a[j]+s[i];
		}
	}
	for(int i=n;i>=1;i--){
		if(s[i]<=m){
			cout<<i;
			return 0;
		}
	}
	return 0;
} 
