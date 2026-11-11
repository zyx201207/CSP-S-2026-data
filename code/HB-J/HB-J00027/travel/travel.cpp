#include<bits/stdc++.h>
using namespace std;
short c1,c2,c3,c4;
string s1,s2;
bool a,b,c,d;
char a1,a2;
int xb(char x,char y){
    if(x-y==1||x-y==-1){
            if((x=='C'&&y=='D')||(y=='C'&&x=='D')){
                return 0;
            }
        return 1;
    }
    else if((x=='D'&&y=='F')||(y=='D'&&x=='F')){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    a1=s1[2];
    a2=s2[2];
    c3=(s1[0]-'0')*10+s1[1]-'0';
    c4=(s2[0]-'0')*10+s2[1]-'0';
    if(c1!=c2){
        cout<<"0000";
    }
    else{
            cout<<1;
        if(c3!=c4){
            cout<<"000";
        }
        else{
            cout<<1;
            if(!((a1>='A'&&a1<='C'&&a2>='A'&&a2<='C')||(a1>='D'&&a1<='F'&&a2>='D'&&a2<='F'))){
                cout<<"00";

            }
            else{
                cout<<1<<xb(a1,a2);

            }
        }
    }
}
