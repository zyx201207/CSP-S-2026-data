#include <bits/stdc++.h>
using namespace std;
int x,y,z,k;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        x=1;
        if(b.substr(0,2)==d.substr(0,2)){
            y=1;
            if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
                z=1;
                if(b[2]=='A'&&d[2]=='B')k=1;
                else if(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))k=1;
                else if(b[2]=='C'&&d[2]=='B')k=1;
            }else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))z=k=1;
        }
    }
    cout<<x<<y<<z<<k;
    return 0;
}