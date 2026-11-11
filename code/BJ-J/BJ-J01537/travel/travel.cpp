#include<bits/stdc++.h>
using namespace std;
string t[1005];
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
t[0]='A';
t[1]='B';
t[2]='C';
t[3]='D';
t[4]='F';
int n,m;
string s,s1;
cin>>n>>s>>m>>s1;
string l="";
string q,w,e,r;
if(n==m){
        l=l+"1";
        for(int i=0;i<2;i++){
  q+=s[i];
  w+=s1[i];
}
e+=s[2];
r+=s1[2];
if(q==w){
        l=l+"1";

        if((e>="A"&&e<="C"&&r>="A"&&r<="C")||(e>="D"&&e<="F"&&r>="D"&&r<="F")){
                l+="1";
int h,k;
for(int i=0;i<5;i++){
    if(t[i]==e)k=i;
    if(t[i]==r)h=i;
}
int o=k-h;
                if(o==1||o==-1)l=l+"1";
                else l+="0";
        }
        else l+="00";
}
else l+="000";
}
else l=l+"0000";


cout<<l;
return 0;
}
