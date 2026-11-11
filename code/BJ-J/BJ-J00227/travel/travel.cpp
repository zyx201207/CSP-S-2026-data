#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int q=0,w=0,e=0,r=0;
    q=(a[0]-'0')*10+(a[1]-'0');
    w=(c[0]-'0')*10+(c[1]-'0');
    if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
        e=0;
    }
    else{
        e=1;
    }
    if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
        r=0;
    }
    else{
        r=1;
    }
    if(q==w){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            if(e==r){
                cout<<1;
                if(b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'||b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='B'){
                    cout<<1;
                    return 0;
                }
                else{
                    cout<<0;
                    return 0;
                }
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
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
}
