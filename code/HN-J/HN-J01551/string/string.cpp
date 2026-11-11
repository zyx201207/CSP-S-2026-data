#include <bits/stdc++.h>
using namespace std;
long long a,b[10110],m,num=0;
char c[10111],d[111111111111];
int main(){
	//freopen("string.in","r","stdin");
	//freopen("string.out","w","stdout");

	for(int i=0;i<a;i++){
		cin>>b[i];
		cin>>c[i];
		m+=b[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<a;j++){
			d[i]=c[i];
		}
	}
	for(int i=0;i<m/2+1;i++){
		if(d[i]!=d[m-i]){
			num++;
		}
	}
	cout<<num;
	return 0;
} 
