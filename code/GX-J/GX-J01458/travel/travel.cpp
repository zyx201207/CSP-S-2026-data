#include<bits/stdc++.h>
using namespace std;

int main(){
	ifstream in("travel.in");
	ofstream out("reavel.out");
    string c1,s1,c2,s2;
    in>>c1>>s1>>c2>>s2;
    if(c1==c2)out<<1;
    else{
        out<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])out<<1;
    else{
        out<<"000";
        return 0;
    }
    int a=(int)(s1[2]-'A'),b=(int)(s2[2]-'A');
    if((a==1||a==2||a==0)&&(b==0||b==1||b==2))out<<1;
    else if((a==4||a==5)&&(b==4||b==5))out<<1;
    else{
        out<<"00";
        return 0;
    }
    if((a==3||a==4)&&(b==4||b==3))out<<0;
    else if(a+1==b)out<<1;
    else if(a-1==b)out<<1;
    else out<<0;
    return 0;
}
