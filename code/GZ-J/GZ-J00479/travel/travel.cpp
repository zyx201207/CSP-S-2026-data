//遵义市滨湖中学 GZ-J00479 胡泽雨 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool st=true;
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i])st=false;
	}
	if(st==true)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(b[i]!=d[i])st=false;
	}
	if(st==true)cout<<"1";
	else{
		cout<<"000";
		return 0;
	}if((b[2]=='A'&&d[2]=='B')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='E')||(b[2]=='C'&&d[2]=='A')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='E'&&d[2]=='D')||(b[2]=='A'&&d[2]=='C'))cout<<"1";
	else {
		cout<<"00";
		return 0; 
	} if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='E')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='E'&&d[2]=='D'))cout<<"1";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
}

