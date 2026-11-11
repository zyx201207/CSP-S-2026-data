#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1=0,f2=0,f3=0,f4=0;
map<char,char> mp;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    mp['A']='B';
    mp['C']='B';
    mp['D']='F';
    mp['F']='D';
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        f1=1;
        string r1=s1.substr(0,2);
        string r2=s2.substr(0,2);
        if(r1==r2){
            f2=1;
            char num1=s1[2];
            char num2=s2[2];
            if((num1>='A'&&num1<='C'&&num2>='A'&&num2<='C')||(num1>='D'&&num1<='F'&&num2>='D'&&num2<='F')){
                f3=1;
                if(num1!='B'){
                    if(mp[num1]==num2) f4=1;
                }
                else{
                    if(mp[num2]==num1) f4=1;
                }
            }
        }
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
