//GZ-J00675,遵义航天高级中学,郑子彧
#include<bits/stdc++.h>
using namespace std;
int a;
int c;
char b;
string k;
int p(string k,int l){
    int x=0;
	string b="",a="";
	for(int i=0;i<l/2;i++){
		a+=k[i];
	}
	for(int i=l-1;i>=l/2+1;i--){
		b+=k[i];
	}
  	for(int i=0;i<=l/2;i++){
  		if(a[i]!=b[i]) x+=1;
	}
	return x;
}
int main(){
	fropen("string.in","r",stdin);
	fropen("string.out","w",stdout);
	cin>>a;
	int x=0;
	for(int i=0;i<a;i++){
		cin>>c>>b;
		for(int j=0;j<c;j++){
			k+=b;
		}
	}
	string k2="";
	int l=k.size();
	cout<<p(k,l);
	return 0;
}
