#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	string n1="",n2="";
	n1[0]=s1[0];
	n1[1]=s1[1];
	n2[0]=s2[0];
	n2[1]=s2[1];
	if(n1==n2) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	char r1=s1[2];
	char r2=s2[2];
	if((r1>='A' && r1<='C') && (r2>='A' && r2<='C') || (r1>='D' && r1<='F') && (r2>='D' && r2<='F')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(r1=='D' || r1=='F'){
		cout<<"1";
	}else if(abs((int)r1-(int)r2)==1) cout<<"1";
	else cout<<"0";
}
