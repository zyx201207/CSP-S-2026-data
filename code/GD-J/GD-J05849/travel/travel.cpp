#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2; cin>>c1>>s1>>c2>>s2;
string a="";
if(c1==c2) a=a+'1';
else a=a+'0';
string tp=s1.substr(0,2);
string tp2=s2.substr(0,2);
if(tp==tp2) a=a+'1';
else a=a+'0';
char k1=s1.back();
char k2=s2.back();
if(k1=='F' && k2!='D') a=a+'0';
else if(k1=='D' && k2!='F') a=a+'0';
else if(tp!=tp2) a=a+'0';
else{
char mc=max(k1,k2);
char mn=min(k1,k2);
int kt=(int)(mc-mn);
if(kt>2) a=a+'0';
else a=a+'1';
}
char mc=max(k1,k2);
char mn=min(k1,k2);
int kt=(int)(mc-mn);
if(kt!=1 || a[0]=='0' || a[2]=='0' || a[1]=='0') a=a+'0';
else a=a+'1';
cout<<a;
return 0;
} 
