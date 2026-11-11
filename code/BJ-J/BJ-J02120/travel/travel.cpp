#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1,s2;
    int c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            char a=s1[2],b=s2[2];
            if(a<='C'&&a>='A'){
                if(b>='A'&&b<='C'){
                    cout<<1;
                    if(abs(int(b)-int(a))==1)cout<<1;
                    else cout<<0;
                }
                else cout<<"00";
            }
            else if(a>='D'&&a<='F'){
                if(b>='D'&&b<='F'){
                    cout<<1;
                    if(abs(int(b)-int(a))==2)cout<<1;
                    else cout<<0;
                }
                else cout<<"00";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else{
        cout<<"0000";
    }
}