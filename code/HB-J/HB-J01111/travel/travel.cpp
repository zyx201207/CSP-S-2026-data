#include<iostream>
#include<cmath>
using namespace std;
string t1,t2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>t1>>s1>>t2>>s2;

    cout<<(t1==t2)?1:0;

    cout<<(s1[0]==s2[0]&&s1[1]==s2[1] && t1==t2)?1:0;

    cout<<((s1[0]==s2[0]&&s1[1]==s2[1]&&t1==t2)
    && (s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'))?1:0;

    cout<<((s1[0]==s2[0]&&s1[1]==s2[1] && t1==t2)
    && (s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C')
    &&(abs(s1[2]-s2[2])==1))?1:0;

    return 0;
}

