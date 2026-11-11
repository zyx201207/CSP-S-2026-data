#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1[0]==x1[0] && r1[1]==x1[1]){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int x,y;
	x=int(r2[0]-'0')*10+int(r2[1]-'0');
	y=int(x2[0]-'0')*10+int(x2[1]-'0');
	if(x==y) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(r2[2]>='A' && x2[2]<='C' || r2[2]>='D' && x2[2]<='F') cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((char(r2[2]+1)==x2[2] || char(r2[2]-1)==x2[2]) && !(r2[2]>='C' && x2[2]<='D')) cout<<1;
	else{
		cout<<0;
	}
	return 0;
}

