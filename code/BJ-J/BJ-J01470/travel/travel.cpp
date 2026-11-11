#include<bits/stdc++.h>
using namespace std;
long long n1,n2,h1,h2,c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n1>>s1>>n2>>s2;
    if(n1==n2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    h1=(s1[0]-'0')*10+s1[1]-'0';
    h2=(s2[0]-'0')*10+s2[1]-'0';
    c1=s1[2]-'A'+1;
    c2=s2[2]-'A'+1;
    if(h1==h2){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if(c1<=3&&c2<=3||c1==4&&c2==6||c1==6&&c2==4){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if(c1<=3&&c2<=3&&(c1+1==c2||c2+1==c1)||c1==4&&c2==6||c1==6&&c2==4){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
