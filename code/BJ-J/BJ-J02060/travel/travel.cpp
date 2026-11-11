#include<bits/stdc++.h>
using namespace std;
int a,b,aa,bb,a1,b1;
string s1,s2,A;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    aa=s1[2]-'A'+1;
    bb=s2[2]-'A'+1;
    a1=(s1[0]-'0')*10+s1[1]-'0';
    b1=(s2[0]-'0')*10+s2[1]-'0';
    if(a1==b1){
        if(aa<=3&&bb<=3){
            if(aa-1==bb||bb-1==aa){
                cout<<"1111";
            }else{
                cout<<"1110";
            }
        }else if(aa>3&&bb>3){
            cout<<"1111";
        }else{
            cout<<"1100";
        }
    }else{
        cout<<"1000";
    }
    return 0;
}
