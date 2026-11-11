#include<bits/stdc++.h>
using namespace std;
int main(){
freooen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,b,c,d;
cin>>a>>b>>c>>d;
if(a==c){
	cout<<"1";
}
else{
	cout<<"0000";
	return 0;
}
int f=0,l=1,y=0;
for(int i=0;i<b.size();i++){
	if(b[i]>='0' and b[i]<='10' and c[i]>='0' and c[i]<='10'){
		if(b[i]!=d[i]){
			f=1;
		}
	}
	if(b[i]>='A' and b[i]<='Z' and d[i]>='A' and d[i]<='Z'){
		if(b[i]+'1'==d[i]+'0' or d[i]+'1'==b[i]+'0'){
			if(b[i]<='C' and d[i]>='C'){
			l=0;	
			}
		}
		else{
			y=1;
		}
	}
}
if(f==0){
	cout<<"1";
}
else{
	cout<<"000";
	return 0;
}
if(l==1){
	cout<<"1";
}
else{
	cout<<"00";
	return 0;
}
if(y==0){
	cout<<"1";
}
else{
	cout<<"0";
}
return 0;
}
