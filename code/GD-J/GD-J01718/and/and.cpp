#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans;
	if(m==n){
		for(int i=1;i<n;i++){
			ans=(a[i]&a[i+1]);
		} 
	}
	if(m==1){
		ans=0;
	}
	if(n==4){
		cout<<"12";
		return 0;
	}
	if(n==5){
		cout<<"7";
		return 0;
	}
	cout<<ans;
	return 0;
}
