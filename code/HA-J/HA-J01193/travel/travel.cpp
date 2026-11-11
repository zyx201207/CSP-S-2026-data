#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a2,b2;
	cin>>a>>a2>>b>>b2;
	if(a==b) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C')||(a2[2]>='D'&&a2[2]<='E'&&b2[2]>='D'&&b2[2]<='E')) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if((a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C'&&(a2[2]+1==b2[2]||a2[2]-1==b2[2]))||(a2[2]>='D'&&a2[2]<='E'&&b2[2]>='D'&&b2[2]<='E')) cout<<"1";
	else cout<<"0";
	return 0;
}
