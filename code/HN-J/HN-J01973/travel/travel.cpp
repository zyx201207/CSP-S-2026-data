#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool a=0,b=0,c=0,d=0;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin >> c1 >> s1 >> c2 >>s2;
a=(c1==c2);
cout << a;
b=(s1[0]==s2[0]&&s1[1]==s2[1])&&a;
cout<< b;
if(s1[2]<='C' && s2[2]<='C'){
c=b;	
}else if(s1[2]>'C'&&s2[2]>'C'){
	c=b;
} 
cout<< c;
d=c&&(s1[2]+1==s2[2]||s1[2]-1==s2[2]);
cout << d;
return 0;
}
