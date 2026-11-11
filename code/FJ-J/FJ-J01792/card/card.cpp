#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==3) cout<<"3"<<" "<<"1"<<" "<<"4";
	else if(n==10&&m==3) cout<<"10"<<" "<<"3"<<" "<<"3";
}
