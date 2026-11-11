#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<=n;i++){
		if(a[i]==a[i+1]){
			cout<<i+3;
			return 0;
		}
	} 
	return 0;
} 
