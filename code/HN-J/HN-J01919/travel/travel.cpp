#include<bits/stdc++.h>
using namespace std;
char c[8][8];
int s[8],s1,s2,l=2,ll=2;
int t[8];
int Jd(int a){
	if(a>=0){
	return a;		
	}
	
	return 0-a;	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
cin>>c[1][1]>>c[1][2];
cin>>c[2][1]>>c[2][2]>>c[2][3];
cin>>c[3][1]>>c[3][2];
cin>>c[4][1]>>c[4][2]>>c[4][3];

//cout<<c[1][1]<<c[1][2]<<endl;
//cout<<c[2][1]<<c[2][2]<<c[2][3]<<endl;
//cout<<c[3][1]<<c[3][2]<<endl;
//cout<<c[4][1]<<c[4][2]<<c[4][3]<<endl;
s1=c[2][3]-64;
s2=c[4][3]-64;
//cout<<s1<<' '<<s2<<endl;
for(int i=1;i<=4;i++){
	s[i]=(c[i][1]-48)*10+c[i][2]-48;
//	cout<<s[i]<<' '; 
}
if(s[1]=s[3]){
	t[0]=1;
}
if(s[2]=s[4]){
	t[1]=1;
}
if(s1-3<=0){
	l=1;
}if(s2-3<=0){
	ll=1;
}
if(l==ll){
	t[2]=1;
}if(l==ll){
	if(Jd(s1-s2)==1){
		t[3]=1;
	}
}
for(int i=0;i<=3;i++){
	cout<<t[i];
}
	return 0;
} 
