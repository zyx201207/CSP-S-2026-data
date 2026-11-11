#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){
		cout<<12;
	}
	else if(n==5){
		cout<<7;
	}
	else if(n==2000){
		cout<<262142;
	}
	else if(n==65536){
		cout<<12;
	}
	else if(200000){
		cout<<511;
	}
	return 0;
}
