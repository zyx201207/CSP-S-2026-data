#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,b1,c1,a2,b2,c2;
    char c[2];
    scanf("%d %d%c %d %d%c",&a1,&b1,&c[0],&a2,&b2,&c[1]);
    c1=c[0]-'A'+1;
    c2=c[1]-'A'+1;
    if(c1==6) c1--;
    if(c2==6) c2--;
    if(a1==a2){
        cout<<1;
        if(b1==b2){
            cout<<1;
            if((c1<4 && c2<4) || (c1>3 && c2>3)){
                cout<<1;
                cout<<(c1-c2==1 || c2-c1==1);
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
}
