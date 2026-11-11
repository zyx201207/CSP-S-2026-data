#include<bits/stdc++.h>
using namespace std;
string c3,c4;
int a,b;
string s1,s2;
int main(){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c3>>s1>>c4>>s2;
	int c1=(c3[0]-'0')*10+(c3[1]-'0');
	int c2=(c4[0]-'0')*10+(c4[1]-'0');
	a=(s1[0]-'0')*10+(s1[1]-'0');
	b=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==b&&c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&a==b&&c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if((s1[2]-s2[2]==1 || s2[2]-s1[2]==1)&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&a==b&&c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	return 0;
}
