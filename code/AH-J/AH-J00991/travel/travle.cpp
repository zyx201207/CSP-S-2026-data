#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    int ss1,ss2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<0;
    }else{
        cout<<1;
    }
    ss1=int(s1[0])*10+int(s1[1])-64;
    ss2=int(s2[0]*10)+int(s2[1])-64;
    if(ss1==ss2&&c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    char down[5]={'A','B','C'};
    char up[5]={'D','F'};
    bool a=true;
    for(int i=0;i<3;i++){
        if(a){
            for(int j=0;j<2;j++){
                if(ss1!=ss2){
                    cout<<0;
                    a=!(true);
                    break;
                }
                if((s1[2]==down[i]&&s2[2]==up[j])||(s1[2]==down[i]&&s2[2]==up[j])||(c1!=c2)&&a){
                    cout<<0;
                    a=!(true);
                    break;
                }
            }
        }
    }
    if(a){
        cout<<1;
    }else{
        cout<<0;
        return 0;
    }
    if(((s1[2]-s2[2]!=1)&&(s2[2]-s1[2]!=1))&&c1!=c2){
        cout<<0;
    }else{
        cout<<1;
    }
    return 0;
}
