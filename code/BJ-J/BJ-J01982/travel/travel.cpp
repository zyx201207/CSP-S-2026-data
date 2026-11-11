#include<bits/stdc++.h>
using namespace std;
char s[4][4];
int c[4],p[5];
bool b[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c[1]>>s[1]>>c[2]>>s[2];
    int s1=0,s2=0;
    for(int i=0;i<2;i++){
        s1*=10;
        s1+=int(s[1][i])-48;
        s2*=10;
        s2+=int(s[2][i])-48;
    }
    if(c[1]!=c[2]){
        cout<<"0000";
        return 0;
    }
    b[1]=1;
    if(s1==s2)b[2]=1;
    if(s[1][2]>='A'&&s[1][2]<='C'){p[1]=1;}
    else {p[1]=2;}
    if(s[2][2]>='A'&&s[2][2]<='C'){p[2]=1;}
    else {p[2]=2;}
    if(p[1]==p[2]&&b[2]) b[3]=1;
    if(abs(int(s[1][2])-int(s[2][2]))==1&&b[3]) b[4]=1;
    for(int i=1;i<=4;i++){
        cout<<b[i];
    }
    return 0;
}