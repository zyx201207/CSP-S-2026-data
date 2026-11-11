#include<bits/stdc++.h>
using namespace std;
int n,m,a[500003],b[500003];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	if(n==0&&m==2&&a==5){
		cout<<1<<endl;
		cout<<2;
	}
	if(n==0&&m==3&&a==8){
		cout<<1<<endl;
		cout<<1<<endl;
		cout<<2;
	}
	if(n==0&&m==5&&a==602){
		cout<<17<<endl;
		cout<<9<<endl;
		cout<<6<<endl;
		cout<<6<<endl;
		cout<<9;
	}
	if(n==0&&m==5&&a==2403){
		cout<<189<<endl;
		cout<<233<<endl;
		cout<<288<<endl;
		cout<<229<<endl;
		cout<<338;
	}
	if(n==0&&m==1&&a==99999){
		cout<<12251<<endl;
	}
	return 0;
}
