#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string p1,p2;
bool f1,f2,f3,f4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)f1=1;
    p1=s1[0]+s1[1];
    p2=s2[0]+s2[1];
    if(p1==p2)f2=1;
    if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C')f3=1;
    if(s1[2]+1==s2[2]||s2[2]+1==s1[2])f4=1;

    if(f1==1){
        cout<<1;
        if(f2==1){
            cout<<1;
            if(f3==1){
                cout<<1;
                if(f4==1)cout<<1;
                else cout<<0;
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
