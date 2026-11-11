#include <bits/stdc++.h>
using namespace std;
int ans[4];
int a1,a2,c1,c2,d1,d2;
string b1,b2;
int main(){
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>a2>>b2;
    c1=int(b1[0]-'0')*10+int(b1[1]-'0');
    d1=int(b1[2]-'A');
    c2=int(b2[0]-'0')*10+int(b2[1]-'0');
    d2=int(b2[2]-'A');
    if(a1==a2){
        ans[0]=1;
        if(c1==c2){
            ans[1]=1;
            if((d1<3&&d2<3)||(d1>2&&d2>2)){
                ans[2]=1;
                if(d1==5) d1-=1;
                if(d2==5) d2-=1;
                if(abs(d1-d2)==1){
                    ans[3]=1;
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        cout<<ans[i];
    }
    return 0;
}
