#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	string str,str1;
	cin>>a>>str>>b>>str1;
	if(a==b)cout<<1;
	else{cout<<"0000";return 0;}
	if(str[0]==str1[0]&&str[1]==str1[1])cout<<1;
	else{cout<<"000";return 0;}
	c=int(str[2]-64);
	d=int(str1[2]-64);
	if((c>=4&&d>=4)||(c<=3&&d<=3))cout<<1;
	else{cout<<"00";return 0;}
	if(abs(c-d)==1)cout<<1;
	else{cout<<"0";return 0;}
	return 0;
}
