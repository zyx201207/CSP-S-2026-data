#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool c3()
{
    char a=s1[2];
    char b=s2[2];
    if((a<='C'&&b<='C')||(a>='D'&&b>='D')){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    bool f=0;
    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            f=1;
        }
    }
    if(f==0){
        cout<<0;
    }
    bool fl=0;
    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<c3;
            fl=1;
        }
    }
    if(fl==0){
        cout<<0;
    }
    bool fla=0;
    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if(c3){
                int a=int(s1[2]);
                int b=int(s2[2]);
                if((a-b==1||a-b==-1)&&(!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')))){
                    cout<<1;
                    fla=1;
                }
            }
        }
    }
    if(fla==0){
        cout<<0;
    }
    return 0;
}
