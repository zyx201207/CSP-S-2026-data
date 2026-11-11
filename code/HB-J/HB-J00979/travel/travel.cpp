#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
char c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
int a=0;
if(c1==c2 && c1!=01 && c1!=16 ){
cout<<a+1;
}else{
cout<<a;
}
int b;
for(int i=0;i<18;i++){
	 b=i;
 }
 int d[100];
 if(b==d[100]){
	 
	 cout<<1;
 }
 else {
	 cout<<0;}
if(s1!=67 && s2!=68){
	cout<<1;}
	else{
		cout<<0;}
	if(s1==65 && s2==66){
		cout<<11;}
	else if(s1==66 && s2==67){
		cout<<11;}	
else if(s1==68 && s2==70){
		cout<<11;}

fclose(stdin);
fclose(stdout);

return 0;
}
