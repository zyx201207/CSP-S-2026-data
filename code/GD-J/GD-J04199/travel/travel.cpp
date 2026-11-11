#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int a1=0,a2=0,a3=0,a4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		a1=1;
	if(c2[0,1]==c4[0,1])
		a2=1;
	}
	if(a2==1){
		if((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(c4[2]=='A'||c4[2]=='B'||c4[2]=='C')){
			a3=1;	
			if((c2[2]=='A'&&c4[2]=='B')||(c2[2]=='B'&&c4[2]=='A')||(c2[2]=='B'&&c4[2]=='C')||(c2[2]=='C'&&c4[2]=='B'))
				a4=1;
	}
		else
			if((c2[2]=='F'||c2[2]=='D')&&(c4[2]=='F'||c4[2]=='D')){
			a3=1;
			a4=1;
		}
}
	cout<<a1<<a2<<a3<<a4<<'\n';
	return 0;
}
