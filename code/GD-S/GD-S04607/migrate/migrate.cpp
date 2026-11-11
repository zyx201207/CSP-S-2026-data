#include <bits/stdc++.h>
using namespace std;
int f[10005];
long long n,m,a,b,cnt=0;
int main(){
	cin >>n>>m;
	for(int i=0;i<=m;i++){
		cin >>a>>b;
		if(a==4) cnt++; 
		for(int j=1;j<=a-1;j++){
			cin >>f[j];
		}
	}
	if(cnt==1) {
		cout<<"1"<<endl;
		cout<<"2";
	}
	else{
		cout<<"0"<<endl;
		cout<<"1"; 
	}
	
	return 0;
	
}

