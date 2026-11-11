#include<bits/stdc++.h>
using namespace std;
char a[5],b[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c1,c2;
    cin>>c1;
    for(int i=1;i<=3;i++){
        cin>>a[i];
    }
    cin>>c2;
    for(int i=1;i<=3;i++){
        cin>>b[i];
    }
    if(c1==c2){
        cout<<"1";
        if(a[1]==b[1]&&b[2]==a[2]){
            cout<<"1";
            if((a[3]=='A'&&(b[3]=='B'||b[3]=='C')||a[3]=='B'&&(b[3]=='A'||b[3]=='C')||a[3]=='C'&&(b[3]=='A'||b[3]=='B'))||(a[3]=='D'&&(b[3]=='E'||b[3]=='F')||a[3]=='E'&&(b[3]=='F'||b[3]=='D')||a[3]=='F'&&(b[3]=='E'||b[3]=='D'))){
                cout<<"1";
                if((a[3]=='A'&&b[3]=='B')||(a[3]=='B'&&(b[3]=='A'||b[3]=='C'))||(a[3]=='F'&&b[3]=='E')||(a[3]=='D'&&b[3]=='E')||(a[3]=='E'&&(b[3]=='D'||b[3]=='F'))||(a[3]=='F'&&b[3]=='E')){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}