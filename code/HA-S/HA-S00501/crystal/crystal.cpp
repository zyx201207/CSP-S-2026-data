#include<bits/stdc++.h>
using namespace std;
long long n,m,a[239999999],s,q;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s=a[i]-a[i-1];
		q+=a[i];
	}
	if(m>=q-a[n]){
		cout<<n;
	}else{
		if(m%s==0){
			if(m/s>=n){
				cout<<n;
			}else
			cout<<m/s;
			
		}else
		cout<<n/s+1;
	}
	if(n==1){
		cout<<1;
 }
	return 0;
}
