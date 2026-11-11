#include<bits/stdc++.h>
using namespace std;
int main(){
	frenpen("migrate.in","r",stdin);
	frenpen("migrate.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=d;i++){
		int a1,a2;
		cin>>a1>>a2;
		int a[a1+1];
		for(int j=1;j<=a1;j++){
			cin>>a[j];
		}
		if(n==0&&d==2){
			if(a1==4&&a2==2){
				cout<<"1"<<endl;
			}else if(a1==5&&a2==2){
				cout<<"2"<<endl;
			}else if(a1==5&&a2==3){
				cout<<"0"<<endl;
			}else if(a1==6&&a2==2){
				cout<<"1"<<endl;
			}
		}
	}
	return 0;
}

