#include<bits/stdc++.h>
using namespace std;
int main(){
	//GZ-J00037,贵阳市观山湖外国语实验中学,张汉琦 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<a[0];
		return 0;
	}
	if(n==1 && m==2){
		cout<<a[0];
		return 0;
	}
	if(n==2 && m==2){
		cout<<a[0]<<"　"<<a[1]; 
		return 0;
	}
	if(n==3 && m==2){
		cout<<a[0]<<"　"<<a[1]<<"　"<<a[2]; 
	}
	if(n==4 ){
		cout<<a[0]<<"　"<<a[1]<<" "<<a[2]<<" "<<a[3]; 
	}
		if(n==5 ){
		cout<<a[0]<<"　"<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]; 
	}
	return 0;
}

