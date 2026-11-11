#include<bits/stdc++.h>
using namespace std;
int r1,x1;
int sum,sum1;
int yu=0;
string r2,x2;
char r,x,r3,r4;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>r1>>r2>>x1>>x2;
if(r1>1&&r1<16&&r1==x1){
cout<<1;
}
else{
	cout<<0;
	yu=1;
}
for(int i=0;i<r2.size();i++){
	if(r2[i]>='1'&&r2[i]<='9'){
		sum+=r2[i]-48;
	}
}
for(int i=0;i<x2.size();i++){
	if(x2[i]>='1'&&x2[i]<='9'){
		sum1+=x2[i]-48;
	}
}
if(sum==sum1&&yu==0){
	cout<<1;
}
else{
	cout<<0;
	yu=1;
}
for(int i=0;i<r2.size();i++){
	if(r2[i]>='A'&&r2[i]<='F'){
		r=r2[i];
	}
}
for(int i=0;i<x2.size();i++){
	if(x2[i]>='A'&&x2[i]<='F'){
		x=x2[i];
	}
}
if(r>='A'&&r<='C'&&x>='A'&&x<='C'&&yu==0){
	cout<<1;
}
else if(r>='D'&&r<='F'&&x>='D'&&x<='F'&&yu==0){
	cout<<1;
}
else{
	cout<<0;
	yu=1;
}
r3=r+1;
r4=r-1;
if(x==r3&&yu==0){
	cout<<1;
}
else if(x==r4&&yu==0){
	cout<<1;
}
else{
	cout<<0;
}
return 0;
}
