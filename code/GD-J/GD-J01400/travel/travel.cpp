#include<bits/stdc++.h>
using namespace std;
bool flag[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string C1,S1,C2,S2;
	cin>>C1>>S1>>C2>>S2;
	char Z1=S1[2],Z2=S2[2];
	memset(flag,0,sizeof(flag));
	if(C1==C2)flag[1]=1;
	if(flag[1]){
		if(S1[0]==S2[0]&&S1[1]==S2[1])flag[2]=1;
	}
	if(flag[2]){
		if(Z1>='A'&&Z1<='C'&&Z2>='A'&&Z2<='C')flag[3]=1;
		else if(Z1>='D'&&Z1<='F'&&Z2>='D'&&Z2<='F')flag[3]=1;
	}
	if(flag[3]){
		if(Z1<='C'&&Z2<='C'){
			if(abs((int)(Z1-Z2))==1)flag[4]=1;
		}
		else{
			if(abs((int)(Z1-Z2))==2)flag[4]=1;
		}
	}
	cout<<flag[1]<<flag[2]<<flag[3]<<flag[4];
	return 0;
}
