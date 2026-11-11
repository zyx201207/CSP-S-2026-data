#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005]; 
bool x(int a,int b){
	return a>b;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sout(a+1,a+1+n,x);
	for(int j=1;j<=m;j++){
		cout<<a[i];
	} 
	return 0;
}

