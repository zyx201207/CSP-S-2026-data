#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    char s1,s2;
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    if(c1==c2) cout<<"1";
    else cout<<"0";
    char a,b;
    a=s1-'A'||s1-'B'||s1-'C'||s1-'D'||s1-'F';
    b=s2-'A'||s2-'B'||s2-'C'||s2-'D'||s2-'F';
    if(a==b) cout<<"1";
    else cout<<"0";
    if(s1-'0'-'1'||s1-'0'-'2'+'1'!=s2-'0'-'1'||s2-'0'-'2') cout<<"1";
    else cout<<"0";
    return 0;
}
