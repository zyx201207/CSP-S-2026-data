#include<bits/stdc++.h>
#include<string>
using namespace std;
bool ce(string a,string b){
return a[0]==b[0]&&a[1]==b[1];
}
bool re(string a,string b,string s1,string s2){
return ce(a,b)==1&&s1[0]==s2[0]&&s1[1]==s2[1];
}
bool se(string a,string b,string s1,string s2){
if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
  return re(a,b,s1,s2)==1;
   }
else{
    return 0;
   }
}
bool n(string a,string b,string s1,string s2){
if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
  return re(a,b,s1,s2)==1;
   }
else{
    return 0;
   }
}


int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,b,c,d;
cin>>a>>b>>c>>d;
cout<<ce(a,c)<<re(a,c,b,d)<<se(a,c,b,d)<<n(a,c,b,d);

return 0;
}

