#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f1,f2,f3,f4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        f1=1;
        if(b[0]==d[0]&&b[1]==d[1]){
            f2=1;
            if(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D'){
                f3=1;
                if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='B'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
                    f4=1;
                }
            }
        }
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
