#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,y1,y2;
    int a,b,c,d;
    cin>>s1>>s2>>y1>>y2;
    if(s2[0]=='0') a=s2[1]-'0';
    else a=(s2[0]-'0')*10+s2[1]-'0';
    if(y2[0]=='0') b=y2[1]-'0';
    else b=(y2[0]-'0')*10+y2[1]-'0';
    if(s2[2]=='A') c=1;
    else if(s2[2]=='B') c=2;
    else if(s2[2]=='C') c=3;
    else if(s2[2]=='D') c=4;
    else if(s2[2]=='F') c=5;
    if(y2[2]=='A') d=1;
    else if(y2[2]=='B') d=2;
    else if(y2[2]=='C') d=3;
    else if(y2[2]=='D') d=4;
    else if(y2[2]=='F') d=5;
    if(s1==y1){
        cout<<1;
        if(a==b){
            cout<<1;
            if(c==4&&d==5||c==5&&d==4||c==1&&d==2||c==1&&d==3||c==2&&d==1||c==2&&d==3||c==3&&d==1||c==3&&d==2||d==1&&c==2||d==1&&c==3||d==2&&c==1||d==2&&c==3||d==3&&c==1||d==3&&c==2){
                cout<<1;
                if(c==4&&d==5||c==5&&d==4||c==1&&d==2||d==1&&c==2||c==2&&d==3||c==3&&d==2){
                    cout<<1;
                }else{
                    cout<<0;
                }
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
