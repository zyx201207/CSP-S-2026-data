#include<iostream>
#include<cmath>
#include<cstring>
#include<string.h>
using namespace std;

int a,b;
string aa,bb;
bool comp(string a,string b){
	if(a[2]=='A'&&b[2]=='B')return 1;
	if(a[2]=='A'&&b[2]=='C')return 1;
	if(a[2]=='B'&&b[2]=='A')return 1;
	if(a[2]=='B'&&b[2]=='C')return 1;
	if(a[2]=='C'&&b[2]=='A')return 1;
	if(a[2]=='C'&&b[2]=='B')return 1;
	if(a[2]=='E'&&b[2]=='F')return 1;
	if(a[2]=='F'&&b[2]=='E')return 1;
	return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> aa >> b >> bb;
	if(a==b)cout<<1;
	else{
		cout << "0000";
		return 0;
	}
	if(aa[0]==bb[0]&&aa[1]==bb[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}if(comp(aa,bb))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(aa[2]-bb[2])==1&&(aa[2]!='C'&&bb[2]!='D')){
		cout << 1;
	}else{
		cout << 0;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
