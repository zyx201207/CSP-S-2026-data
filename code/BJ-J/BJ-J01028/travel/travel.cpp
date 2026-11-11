#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,c,b,d;
    int e=0,f=0,g=0,h=0;
    cin>>a>>b>>c>>d;
    if(a==c) {
        e=1;
        if(b[0]==d[0] && b[1]==d[1]){
            f=1;
            if((b[2]>='D' && d[2]>='F') || (b[2]<='C' && d[2]<='C')){
                g=1;
                if((b[2]>='D' && d[2]>='F') || (abs(b[2]-d[2])==1)) h=1;
            }
        }
    }
    if(h==1) printf("1111\n");
    else if(g==1) printf("1110\n");
    else if(f==1) printf("1100\n");
    else if(e==1) printf("1000\n");
    else printf("0000\n");
    return 0;
}
