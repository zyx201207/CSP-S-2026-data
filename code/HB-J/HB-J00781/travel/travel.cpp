#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    //同一节车厢
    if(c1==c2) cout<<1;
    else cout<<0;
    //同一节车厢的同一排
    if(c1==c2&&(s1[0]==s2[0]&&s1[1]==s2[1])) cout<<1;
    else cout<<0;
    //同一节车厢的同一排
    if(c1==c2&&(s1[0]==s2[0]&&s1[1]==s2[1])){
            //过道的同一侧
            if((s1[2]<='C'&&s1[2]>='A')==(s2[2]<='C'&&s2[2]>='A')){
                cout<<1;
                //是否相邻
                if(s1[2]+1==s2[2]||s2[2]+1==s1[2]) cout<<1;
                else cout<<0;
            }
            else cout<<0<<0;
    }
    else cout<<0<<0;

    return 0;
}
