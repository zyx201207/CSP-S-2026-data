//GZ-J00158 六盘水市第二十四中学 朱思怡 
#include<bits/stdc++.h>
using namespace std;
char  zwr[3],zwx[3];
string cxr,cxx,srl,sxl;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cxr>>zwr[0]>>zwr[1]>>zwr[2];
	cin>>cxx>>zwx[0]>>zwx[1]>>zwx[2];
	for(int i=0;i<=1;i++){
		srl+=zwr[i];
		sxl+=zwx[i]; 
	}
	char r=zwr[2],x=zwx[2];
	if(cxr==cxx){
		cout<<1;
		if(srl==sxl){
		 cout<<1;
		 if(r=='A'&&x=='B'||r=='B'&&x=='A'){
			cout<<1<<1;
		 }
		 else if(r=='B'&&x=='C'||r=='C'&&x=='B'){
			cout<<1<<1;
		 }
		 else if(r=='D'&&x=='F'||r=='F'&&x=='D'){
			cout<<1<<1;
		 }
		 else if(r=='A'&&x=='C'||r=='C'&&x=='A'){
			cout<<1<<0;
		 }
		 else{
		 	cout<<0<<0;
		 	return 0;
		 }
			
		}
		else{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
