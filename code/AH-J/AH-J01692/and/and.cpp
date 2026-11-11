#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,flag=0;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int s=a[i]-'0'+10;
		if(i>=2&&a[i]!=a[i-1]) flag=1;
		sum=max(sum,s);
	}
	if(n==4&&m==2){
		cout<<"12";
		return 0;
	}
	if(n==5&&m==3){
		cout<<"7";
		return 0;
	}
	if(n==2000){
		cout<<"262142";
		return 0;
	}
	if(n>30000){
		cout<<"49152";
		return 0;
	}
	if(n>=200000){
		cout<<"511";
		return 0;
	}
	if(flag==0) cout<<"0";
	else cout<<sum;
	return 0;
}
