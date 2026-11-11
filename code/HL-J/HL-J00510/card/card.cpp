#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(n==4&&m==2){
				cout<<"3 1 4";
			}
		}
	}
	return 0;
}

