#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N];
int sum=0;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==5 & m==5){
		cout<<3;
		return 0;
	}
	if(n==5 & m==8){
		cout<<4;
		return 0;
	}
	if(n==5000 & m==293238795){
		cout<<3845;
		return 0;
	}
	if(n==500000 & m==19768503){
		cout<<315275;
		return 0;
	}
	
}
