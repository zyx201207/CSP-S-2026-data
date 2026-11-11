#include<bits/stdc++.h>
using namespace std;
struct seat{
    char a,b,c,d,e;
}s[2];
bool cmp[4];
void cmp1(seat x,seat y){
    if(x.a==y.a&&x.b==y.b){
        cmp[0]=1;
        if(x.c==y.c&&x.d==y.d){
            cmp[1]=1;
            if(((x.e=='A'||x.e=='B'||x.e=='C')&&(y.e=='A'||y.e=='B'||y.e=='C'))||((x.e=='D'||x.e=='F')&&(x.e=='D'||x.e=='F'))){
                cmp[2]=1;
                if((x.e=='D'||x.e=='F')&&(x.e=='D'||x.e=='F'))cmp[3]=1;
                else{
                    if(abs((x.e-'A')-(y.e-'A'))==1){
                        cmp[3]=1;
                    }
                }
            }
        }
    }
    return;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s[0].a>>s[0].b>>s[0].c>>s[0].d>>s[0].e>>s[1].a>>s[1].b>>s[1].c>>s[1].d>>s[1].e;
    cmp1(s[0],s[1]);
    cout<<cmp[0]<<cmp[1]<<cmp[2]<<cmp[3];
    return 0;
}
