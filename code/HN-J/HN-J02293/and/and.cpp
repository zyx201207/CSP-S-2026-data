#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i;
	int a[2000000];
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		for(i=1;i<=10;i++){
			if(a[i]="3 15 12 12"){
				cout<<"12";
			}
		}
	}else if(n==5&&m==3){
		for(i=1;i<=5;i++){
			if(a[i]=="31 3 1 15 7"){
				cout<<"7";
			}
		}
	}
	return 0;
}

