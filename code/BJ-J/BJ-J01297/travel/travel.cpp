#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int num1,num2;
int z1,z2;
bool flag=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>num1>>s1>>num2>>s2;
    z1=(s1[0]-'0')*10+s1[1]-'0';
    z2=(s2[0]-'0')*10+s2[1]-'0';
    if(num1==num2) cout<<1;
    else {
        cout<<0;
        flag=0;
    }
    if(z1==z2&&flag) cout<<1;
    else cout<<0;
    if(((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E'))&&flag)cout<<1;
    else cout<<0;
    if((s1[2]+1==int(s2[2])||s1[2]-1==int(s2[2]))&&flag) cout<<1;
    else cout<<0;
    return 0;
}
