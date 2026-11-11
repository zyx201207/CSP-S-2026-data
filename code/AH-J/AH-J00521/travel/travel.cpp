#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans="";
bool where(string s11,char s12,string s21,char s22){
    return ((s12=='A'||s12=='B'||s12=='C')&&(s22=='A'||s22=='B'||s22=='C'))||((s12=='D'||s12=='E')&&(s22=='D'||s22=='E'));
}
bool near(char s12,char s22){
    return (((int)(s12)+1==(int)(s22)||(int)(s12)-1==(int)(s22)))&&((s12!='C'||s22!='D')&&(s12!='D'||s22!='C'));
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)ans=ans+"1";
    else ans=ans+"0";

    string s11=s1.substr(0,2);
    char s12=s1[2];
    string s21=s2.substr(0,2);
    char s22=s2[2];
    if(s11==s21&&c1==c2)ans=ans+"1";
    else ans=ans+"0";

    if(s11==s21&&c1==c2&&where(s11,s12,s21,s22)==1)ans=ans+"1";
    else ans=ans+"0";

    if(s11==s21&&c1==c2&&near(s12,s22)==1)ans=ans+"1";
    else ans=ans+"0";
    cout<<ans;
    return 0;
}
