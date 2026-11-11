#include <bits/stdc++.h>
using namespace std;
char c1[3],c2[3],s1[4],s2[4];
char s[6];
int ss1,ss2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    s[1]='A';
    s[2]='B';
    s[3]='C';
    s[4]='D';
    s[5]='E';
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<1;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
        for(int i=1;i<=5;i++){
            if(s1[2]==s[i]){
                ss1=i;
                break;
            }
        }
        for(int i=1;i<=5;i++){
            if(s2[2]==s[i]){
                ss2=i;
                break;
            }
        }
        if((ss1<=3&&ss2<=3)||(ss1>=4&&ss2>=4)){
            cout<<1;
        }
        else{
            cout<<0<<0;
            return 0;
        }
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }
    if(abs(ss1-ss2)==1){
        cout<<1;
    }
    else{
        cout<<0;
    }


    return 0;
}
