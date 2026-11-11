#include<bits/stdc++.h>
using namespace std;
string c1,c2,z1,z2,x1,x2;
bool a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>c1>>z1;
	x1=z1[0]+z1[1];
	cin>>c2>>z2;
	x2=z2[0]+z2[1];
	if(c1==c2) a1=1;
	else{
		cout<<0<<0<<0<<0<<endl;
		return 0;
	}
	if(x1==x2){
		a2=1;
		if((z1[2]=='A'||z1[2]=='B'||z1[2]=='C')&&(z2[2]=='A'||z2[2]=='B'||z2[2]=='C')){
			a3=1;
			if((z1[2]=='A'&&z2[2]=='B')||(z1[2]=='B'&&z2[2]=='C')||(z2[2]=='A'&&z1[2]=='B')||(z2[2]=='B'&&z1[2]=='C'))
				a4=1;
			else a4=0;
		}else if((z1[2]=='D'||z1[2]=='F')&&(z2[2]=='D'||z2[2]=='F')){
			a3=1;
			a4=1;
		}else{
			cout<<a1<<a2<<0<<0;
			return 0;
		}
	}else{
		cout<<a1<<0<<0<<0<<endl;
		return 0;
	}cout<<a1<<a2<<a3<<a4<<endl;
	return 0;
}
