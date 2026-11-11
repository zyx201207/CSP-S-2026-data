#include<bits/stdc++.h>>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long k=a[1]+m;
	for(long long i=1;i<=m;i++){
		if(a[i]>k){
			cout<<i;
			break;
		}
	}
	
	
	
	return 0;
} 
