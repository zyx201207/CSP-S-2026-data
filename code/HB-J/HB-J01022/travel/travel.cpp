#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;

int ce(string ch){
    if(ch=="A"||ch=="B"||ch=="C") return 1;
    if(ch=="D"||ch=="F") return 2;
}

int xl(string ch){
    if(ch=="A") return 1;
    if(ch=="B") return 2;
    if(ch=="C") return 3;
    if(ch=="D") return 5;
    if(ch=="F") return 6;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    bool b1=(s1==s3);
    string str1,str2;
    str1=s2.substr(0,2);
    str2=s4.substr(0,2);
    bool b2=(s1==s3&&str1==str2);
    string c1=s2.substr(2);
    string c2=s4.substr(2);
    bool b3=(s1==s3&&str1==str2&&ce(c1)==ce(c2));
    bool b4=(s1==s3&&str1==str2&&ce(c1)==ce(c2)&&abs(xl(c1)-xl(c2))==1);
    cout<<b1<<b2<<b3<<b4;
    return 0;
}

//It's easy
//But I can't do anymore
//I hope I can get 160
//eee
