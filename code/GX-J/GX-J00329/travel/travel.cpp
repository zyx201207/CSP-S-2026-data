#include <bits/stdc++.h>
using namespace std;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
int n=s1.size(),m=s2.size();
if(c1==c2){
    cout<<1;
    if(s1[0]==s2[0] && s1[1]==s2[1]){
        cout<<1;
        if((s1[2]<='D' && s2[2]<='D' || s1[2]<='C' && s2[2]<='C')){//两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧
            cout<<1;
            if((abs(s1[2]-s2[2])==1)) cout<<1;
            else cout<<0;
        }
        else cout<<0;
    }
    else cout<<0;
}
else cout<<0000;
return 0;
}
