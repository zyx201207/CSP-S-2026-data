#include<bits/stdc++.h>
using namespace std;
char a[2],b[3],c[2],d[3];
int aton,cton,bton,dton;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<2;i++)cin>>a[i];
    for(int i=0;i<3;i++)cin>>b[i];
    for(int i=0;i<2;i++)cin>>c[i];
    for(int i=0;i<3;i++)cin>>d[i];
    aton=(a[0]-'0')*10+(a[1]-'0');
    bton=(b[0]-'0')*10+(b[1]-'0');
    cton=(c[0]-'0')*10+(c[1]-'0');
    dton=(d[0]-'0')*10+(d[1]-'0');
    if(aton==cton){
        cout<<1;
        if(bton==dton){
            cout<<1;
            if((b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C'))cout<<"00";
            else{
                cout<<1;
                int chalas=abs(b[2]-d[2]);
                if(chalas==1)cout<<1;
                else cout<<0;
            }
        }
        else{
            cout<<"000";
        }
    }
    else cout<<"0000";
    return 0;
}
