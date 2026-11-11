#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==0){
		cout<<n;
	}
	if(m<=n&&m!=0){
		cout<<n;
	}
	if(m>n){
		cout<<n;
	} 
	return 0;
} 
