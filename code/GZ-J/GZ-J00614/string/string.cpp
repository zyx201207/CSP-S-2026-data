// Gz-JOO614 遵义市第四初级中学 李浩然  
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	int a;
	cin>>a;
	char z;
	char az[a];
	int z1;
	int az1[a];
	string s;
	int zd=0;
	for(int i=0;i<a;i++){
		cin>>z1;
		zd=z1;
		az1[i]=z1;
		cin>>z;
		az[i]=z;
	      
		for(int j=0;j<z1;j++){
			s=s+z;
		}
	}
	bool b=0;
     for(int i=0;i<s.size();i++){
     	if(s[i]=s[i+1]){
		 }
     	else{
     		b==1;
		 }
	 }
	 if(b==0){
	 	cout<<"0";
	 }
	else{
		cout<<zd;
		
	}

		
	}

