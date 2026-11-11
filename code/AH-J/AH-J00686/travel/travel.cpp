#include<iostream>
#include<cstdio>
using namespace std;
int c1,c2;
string s1,s2;
bool check1(char a,char b){
    if(a>b){
        char r=b;
        b=a;
        a=r;
    }
    return (a=='D'&&b=='F')||(a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='C');
}
bool check2(char a,char b){
    if(a>b){
        char r=b;
        b=a;
        a=r;
    }
    return (a=='D'&&b=='F')||(a=='A'&&b=='B')||(a=='B'&&b=='C');
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(check1(s1[2],s2[2])){
                cout<<1;
                if(check2(s1[2],s2[2])) cout<<1;
                else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
