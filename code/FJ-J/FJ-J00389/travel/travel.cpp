#include <bits/stdc++.h>
using namespace std;
char a[3],b[3],c[5],d[5];
int m,n;
bool f(){
	for(int i=1;i<=2;i++){
		if(a[i]!=b[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3;i++){
		cin>>c[i];
	}
	for(int i=1;i<=2;i++){
		cin>>b[i];
	}
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	m=0;
	n=0;
	if(f()==1){
		cout<<"1";
	}
	else{
	cout<<"0000";
	return 0;
	}
	for(int i=1;i<=2;i++){
		m=m*10+int(c[i]-'0');
		n=n*10+int(d[i]-'0');
	}
	if(m==n){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(c[3]>='A'&&c[3]<='C'&&d[3]>='A'&&d[3]<='C'){
		cout<<"1";
		if(c[3]+1==d[3]||d[3]+1==c[3]){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else if(c[3]>='D'&&c[3]<='E'&&d[3]>='D'&&d[3]<='E'){
		cout<<"11";
	}
	else{
		cout<<"00";
	}
	return 0;
} 
