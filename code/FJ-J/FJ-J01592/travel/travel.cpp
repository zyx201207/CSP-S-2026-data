#include<bits/stdc++.h>
using namespace std;
//const int N=
//#define int long long
signed main(){
	   freopen("travel.in","r",stdin);
	   freopen("travel.out","w",stdout);
	   string Xc,Xz,Rc,Rz;
	   cin>>Xc>>Xz>>Rc>>Rz;
	   
	   if(Xz[2]=='F'){
	   	Xz[2]='E';
	   }
	   if(Rz[2]=='F'){
	   	Rz[2]='E';
	   }//cout<<Xz<<' '<<Rz;
	   
	   int X=(Xc[0]-48)*10+Xc[1]-48,R=(Rc[0]-48)*10+Rc[1]-48;
	   if(X==R){
	   	cout<<1;
	   }else{
	   	cout<<0<<0<<0<<0;
	   	return 0;
	   }
	   X=(Xz[0]-48)*10+Xz[1]-48;
	   R=(Rz[0]-48)*10+Rz[1]-48;
	   if(X==R){
	   	cout<<1;
	   }else{
	   	cout<<0<<0<<0;
	   	return 0;
	   }
	   if(((Xz[2]=='A'||Xz[2]=='B'||Xz[2]=='C')&&(Rz[2]=='A'||Rz[2]=='B'||Rz[2]=='C'))||((Xz[2]=='D'||Xz[2]=='E')&&(Rz[2]=='D'||Rz[2]=='E'))){
	   	cout<<1;
	   }else{
	   	cout<<0<<0;
	   	return 0;
	   }
	   int j=abs(Xz[2]-Rz[2]);
	   if(j==1){
	   	cout<<1;
	   }else{
	   	cout<<0;
		return 0;
	   }
	   
}

