#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,b,c[20005]={},e[20005]={};
	int d,k=0;
	long long f[20005]={},z=0;
	cin>>d;
	for(int i=1;i<=d;i++){
		cin>>f[i];
		cin>>c[i];
		for(int j=1;j<=f[i];j++){
			e[j+z]=c[i];
		}
		z+=f[i];
	}
	a=c[1];
	for(int i=1;i<=d;i++){
		if(c[i]!=a)
			k=1;
	}
	if(k==0){
		cout<<0;
	}
	return 0;
	//ÓÃ±©Á¦°É£¿ 
} 
