#include<bits/stdc++.h>
#include<a.out.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    int w=0,x=0,y=0,z=0;
    cin>>a>>b>>c>>d;
    if(a==c){
        w=1;
        if(b[0]==d[0]&&b[1]==d[1]){
            x=1;
            if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
                y=1;
                if(b[2]+1==d[2]||b[2]-1==d[2])z=1;
                }
            else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')){
                y=1;
                if(b[2]+2==d[2]||b[2]-2==d[2])z=1;
                }
            }
        }
    cout<<w<<x<<y<<z;

    return 0;
    }
