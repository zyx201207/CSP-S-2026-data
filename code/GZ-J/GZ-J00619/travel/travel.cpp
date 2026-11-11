//GZ-J00619 北京师范大学贵阳附属中学 杨然
#include <bits/stdc++.h>
using namespace std;
long long c1,c2;
string s1,s2;
char s(string a){
	for(int i=0;i<3;i++){
		if(a[i] >='A' &&a[i]<='F')return a[i];
	}
}
bool line(string a,string b){
    int x=0,y=0;
    for(int i = 0;i < 3;i++){
    	x = x * 10;
    	y = y * 10;
    	if(a[i]>='0' && a[i]<='9'){
    		x+=a[i];
		}
		if(b[i]>='0' && b[i]<='9'){
    		y+=b[i];
		}
	}
    if(x==y)return true;
    else return false;
}
bool way(string c,string d,char a,char b){
	if(line(c,d)&&(a<='C'&&b<='C' || a>='D'&&b>='D'))return true;
	else return false;
}
bool seat(string x,string y,char a,char b){
	if(line(x,y) && way(x,y,a,b) && (a-1 ==b || a+1 == b))return true;
	else return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}	
	else{
		cout<<"1";
		if(line(s1,s2))cout<<"1";
		else cout<<"0";
		char x = s(s1),y = s(s2);
		if(way(s1,s2,x,y))cout<<"1";
		else cout<<"0";
		if(seat(s1,s2,x,y))cout<<"1";
		else cout<<"0";
	}
	return 0;
} 
