#include<bits/stdc++.h>
using namespace std;
string a,b;
char a1,a2,a3,b1,b2,b3;
int t=1;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a;
cin>>a1>>a2>>a3;
cin>>b;
cin>>b1>>b2>>b3;
while(t) {
if(a==b){
	cout<<"1";
}else{
	cout<<"0000"<<endl;
	break;
}
if(a1==b1&&a2==b2){
	cout<<"1";
}else{
	cout<<"000"<<endl;
	break;
}
if((a3=='D' && b3=='F')||(a3=='F' && b3=='D')){
	cout<<"11"<<endl;
	break;}
if((a3=='D'&&b3!='F')||(a3=='F'&&b3!='D')||(a3!='D' && b3=='F')||(a3!='F'&& b3=='D')){
	cout<<"00"<<endl;
	break;
}
if((a3=='A'&&b3=='C')||(a3=='C'&&b3=='A')){
	cout<<"10"<<endl;
}else{
	cout<<"11"<<endl;
}



t--;
}
	return 0;
}
