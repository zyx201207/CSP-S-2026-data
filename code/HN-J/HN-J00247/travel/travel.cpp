#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
bool ans[5];
bool f=1;
bool xl(char x,char y){
	bool flag;
	if(sr[2]>='D'&&sr[2]<='F'&&sx[2]>='D'&&sx[2]<='F')flag=1;
	else if(!((x=='A'&&y=='C')||(y=='A'&&x=='C')))flag=1;
	else flag=0;
	return flag; 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);//È¥×¢ÊÍ£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
	cin>>cr>>sr>>cx>>sx;
	for(int i=0;i<2;i++){
		if(cr[i]!=cx[i])f=0;
	}
	if(f)ans[1]=1;
	f=1;
	if(ans[1]){
		for(int i=0;i<2;i++){
			if(sr[i]!=sx[i])f=0;
		}
		if(f)ans[2]=1;
		f=1;
		if(ans[2]){
			if(!((sr[2]>='A'&&sr[2]<='C'&&sx[2]>='A'&&sx[2]<='C')||(sr[2]>='D'&&sr[2]<='F'&&sx[2]>='D'&&sx[2]<='F')))f=0;
			if(f)ans[3]=1;
			f=1;
			if(ans[3]){
				if(!xl(sr[2],sx[2]))f=0;
				if(f)ans[4]=1;
				f=1;
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
}
