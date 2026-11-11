#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int e[] = {0,0,0,0,0};
    if(a[0]==c[0]&&c[1]==a[1]){
        e[0] = 1;
        if(b[0]==d[0]&&b[1]==d[1]){
            e[1] = 1;
            if(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D'){
                e[2] = 1;
                if((b[2]==d[2]+1||d[2]-'A'==b[2]-'A'+1)||(b[2]=='D'||d[2]=='D')){
                    e[3] = 1;
                }
            }
        }
    }
    cout<<e[0]<<e[1]<<e[2]<<e[3];
    return 0;
}