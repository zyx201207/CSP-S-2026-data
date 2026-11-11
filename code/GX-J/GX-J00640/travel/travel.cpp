#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int m,n;
char z1,z2;
int b[5]={0};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> s1 >> c1 >> s2 >> c2;
    m=stoi(c1);
    n=stoi(c2);
    z1=c1[2];
    z2=c2[2];
    if(s1!=s2){
        cout << "0000";
        return 0;
    }
    if(s1==s2){
        b[1]=1;
    }
    if(m==n){
        b[2]=1;
    }
    if((m==n)&&((z1<='C' && z2<='C')||(z1>='D' && z2<='D'))){
        b[3]=1;
    }
    if((m==n)&&((z1<='C' && z2<='C')||(z1>='D' && z2<='D'))&&(z1!='C' && z2!='C' && z1!='D' && z2!='D'&& abs(z1-z2)==1)){
        b[4]=1;
    }
    cout << b[1] << b[2] << b[3] << b[4];
    return 0;
}
