#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<1;
        int x = (c[0]-'0')*10+(c[1]-'0');
        int y = (d[0]-'0')*10+(d[1]-'0');
        if(x==y){
            cout<<1;
            char m=c[2];
            char n=d[2];
            if(((m=='A'||m=='B'||m=='C')&&(n=='A'||n=='B'||n=='C'))||((m=='D'||m=='F')&&(n=='D'||n=='F'))){
                cout<<1;
                if(((m-n)==1)||((m-n)==-1)){
                    cout<<1;
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
