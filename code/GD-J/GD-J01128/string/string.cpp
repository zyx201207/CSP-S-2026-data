#include<iostream>
#include<cstdio>
using namespace std;
long long  a,s[100000],d[100000],g=-1,sum=0;
char f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int j=0;j<a;j=j+1){
		cin>>s[j]>>f;
		for(int k=0;k<s[j];k=k+1){
			g=g+1;
			d[g]=f-'a';
			
		}
		
	}
	//while(2){
	//	bool a=0;
		if(g%2==0){
		for(int j=0;j<g/2;j=j+1){
			if(d[j]!=d[g-j]){
			   sum=sum+1;	//bool a=1;
			}
		}
	}
	else{
		for(int j=0;j<(g+1)/2;j=j+1){
			if(d[j]!=d[g-j]){
			sum=sum+1;//	bool a=1;
			}
		}
	}
	//if(a==0){
	//	break;
	//}
	
	
	cout<<sum;
	return 0;
}
