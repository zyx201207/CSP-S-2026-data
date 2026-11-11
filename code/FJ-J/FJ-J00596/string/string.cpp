#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b,j,sum=0;
	long long f=0;
	long long i=0;
	string c="",d;
	char e;
	cin>>a;
	for (i;i<a;i++){
		cin>>b>>d;
		f+=b;
		for(j=0;j<b;j++)c+=d;
		
	}
	for(i=0;i<(f/2);i++){
		if(c[i]!=c[f-i-1])sum++;
	}
	cout<<sum; 
	return 0;
} 
