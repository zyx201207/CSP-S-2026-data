//GZ-J00636 µË²ıª
#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,zw1,zw2;
long long a1,a3,a2,a4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    a1=s1[0]-'0'*10+s1[1]-'0';
    a3=s3[0]-'0'*10+s3[1]-'0';
    if(a1==a3){
        cout<<1;
    }
    else{
        cout<<0;
    }
    a2=s2[0]-'0'*10+s2[1]-'0';
    a4=s4[0]-'0'*10+s4[1]-'0';
    if(a2==a4&&a1==a3){
        cout<<1;
    }
    else{
        cout<<0;
    }
    zw1=s2[2];
    zw2=s4[2];
    if((zw1=="D"&&zw2=="F")||(zw1=="F"&&zw2=="D")||(zw1=="A"&&zw2=="B")||(zw1=="B"&&zw2=="A")||(zw1=="A"&&zw2=="C")||(zw1=="C"&&zw2=="A")||(zw1=="B"&&zw2=="C")||(zw1=="C"&&zw2=="B")){
        if(a2==a4&&a1==a3){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
    if((zw1=="D"&&zw2=="F")||(zw1=="F"&&zw2=="D")||(zw1=="A"&&zw2=="B")||(zw1=="B"&&zw2=="A")||(zw1=="B"&&zw2=="C")||(zw1=="C"&&zw2=="B")){
        if(a2==a4&&a1==a3){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }

    return 0;
}
