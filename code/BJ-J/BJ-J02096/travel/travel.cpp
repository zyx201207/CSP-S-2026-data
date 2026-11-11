#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[3],s2[3];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<0<<0<<0<<0;
        return 0;
    }else{
        cout<<1;
        int ss1=(s1[0]-'0')*10+s1[1]-'0';
        int ss2=(s2[0]-'0')*10+s2[1]-'0';
        if(ss1!=ss2){
            cout<<0<<0<<0;
            return 0;
        }else{
            cout<<1;
            if(max(s1[2],s2[2])<='C'&&min(s1[2],s2[2])>='A'){
                cout<<1;
                if(abs(s1[2]-s2[2])==1)cout<<1;
                else cout<<0;
            }else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))cout<<1<<1;
            else cout<<0<<0;
        }
    }
    return 0;
}
