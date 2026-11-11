#include<bits/stdc++.h>
using namespace std;
string trainr,setr,trainx,setx,out="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>trainr>>setr>>trainx>>setx;
	if(trainr==trainx) out[0]='1';
	if(setr[0]==setx[0] && setr[1]==setx[1] && out[0]=='1') out[1]='1';
	if(((setr[2]<='C'&& setx[2]<='C') || (setr[2]>='D'&& setx[2]>='D')) && out[1]=='1') out[2]='1';
	if((setr[2]-setx[2]<=1 && setr[2]-setx[2]>=-1) && out[2]=='1' && out[2]=='1') out[3]='1';
	cout<<out<<endl;
	return 0;
} 
