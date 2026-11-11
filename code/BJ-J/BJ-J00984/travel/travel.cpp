#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int t1,t2;
    string s1,s2;
    cin>>t1>>s1>>t2>>s2;
    if(t1!=t2) {
        cout<<0000;
        return 0;
    }
    else cout<<1;
    if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
    else {
        cout<<000;
        return 0;
    }
    bool f1=(s1[2]=='A'&&s2[2]=='B');
    bool f2=(s1[2]=='B'&&s2[2]=='A');
    bool f3=(s1[2]=='B'&&s2[2]=='C');
    bool f4=(s1[2]=='C'&&s2[2]=='B');
    bool f5=(s1[2]=='D'&&s2[2]=='F');
    bool f6=(s1[2]=='F'&&s2[2]=='D');
    bool sf1=(s1[2]=='A'&&s2[2]=='C');
    bool sf2=(s1[2]=='C'&&s2[2]=='A');
    if(f1||f2||f3||f4||f5||f6)
        cout<<11;
    else if(sf1||sf2)
        cout<<10;
    else cout<<00;
    return 0;
}
