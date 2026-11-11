#include<bits/stdc++.h>
using namespace std;
#define ll long long
int er(int a){
	int s=0;
	while(a){
		s*=10;
		s+=a%2;
		s/=2;
	}
	int p=0;
	while(s){
		p*=10;
		p+=s%10;
		s/=10;
	}
	return s;
	
}
int jie(int n){
	int n1=n;
	for(int i=1;i<n1;i++){
		n*=i;
	}
	return n;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	}
//	for(int i=2;i<=m;i++){
//		for(int j=1;j<=jie(n)/(jie(n-i)*jie(i));j++){
			
//		}
//	}
	
	
	
	return 0;
} 
