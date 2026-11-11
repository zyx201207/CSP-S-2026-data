#include<bits/stdc++.h>
using namespace std;
int rc,xc;
string r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>r>>xc>>x;
	if(rc==xc)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if((r[0]==x[0])&&(r[1]==x[1]))cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((r[2]<='C')&&(x[2]<='C')||(r[2]>='D')&&(x[2]>='D'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(int(r[2])-int(x[2]))==1)cout<<1;
	else cout<<0;
	return 0;
}
