#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			cout<<a[i];
			return 0;
		}
	}
	return 0;
} 
