//GZ-J00301-观山湖区第八中学-金煜文
#include <bits/stdc++.h>
using namespace std;
char s1[10],c1[10],s2[10],c2[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++){
        char t;
        cin>>t;
        if(t!=' ') s1[i]=t;
    }
    for(int i=1;i<=3;i++){
        char t;
        cin>>t;
        if(t!=' ') c1[i]=t;
    }
    for(int i=1;i<=2;i++){
        char t;
        cin>>t;
        if(t!=' ') s2[i]=t;

    }
    for(int i=1;i<=3;i++){
        char t;
        cin>>t;
        if(t!=' ') c2[i]=t;
    }
    if(s1[1]==s2[1]&&s1[2]==s2[2]){
        cout<<'1';
        if(c1[1]==c2[1]&&c1[2]==c2[2]){
            cout<<'1';
            if(c1[3]>='D'&&c2[3]>='D'){
                cout<<"11";
            }
            else if(c1[3]<='C'&&c2[3]<='C'){
                cout<<"1";
                if((c1[3]=='A'&&c2[3]=='B')||(c1[3]=='B'&&c2[3]=='A')) cout<<'1';
                else if((c1[3]=='B'&&c2[3]=='C')||(c2[3]=='B'&&c1[3]=='C')) cout<<'1';
                else cout<<'0';
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
