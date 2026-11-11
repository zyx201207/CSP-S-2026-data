#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=true,b=true,c=false,d=false,q=false;
	if(c1!=c2){
		a=false;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			b=false;
		}
	}
	if(a==false&&b==true){
		b=false;
	}
	if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'&&b==true){
		c=true;
	}else if(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'&&b==true){
		c=true;
		q=true;
	}
	if(q){
		d=true;
	}
	if(int(s1[2])-int(s2[2])==1&&c==1){
		d=true;
	}else if(int(s2[2])-int(s1[2])==1&&c==1){
		d=true;
	}
	cout<<a<<b<<c<<d;
return 0;
} 
