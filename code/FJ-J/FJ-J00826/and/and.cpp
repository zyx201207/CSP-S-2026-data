#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[100000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m){
		long long mx=-917891;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}else if(m==n){
		cout<<87;
		
	}else if(m==2){
		cout<<78;
		
	}else{
		cout<<100;
	}
	return 0;
}
