#include <bits/stdc++.h>
using namespace std;

string ans="0000";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2){//同一节车厢
        ans[0]='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){//同一排
            ans[1]='1';
            if( (s1[2]=='D' && s2[2]=='F') || (s1[2]!='D'&&s1[2]!='F'&&s2[2]!='D'&&s2[2]!='F') ){//过道的同一侧
                ans[2]='1';
                int seat1=s1[2]-'A';
                int seat2=s2[2]-'A';
                if( abs(seat1-seat2) <= 1 ){//座位是否相邻
                    ans[3]='1';
                }else{
                    cout<<ans;
                    return 0;
                }

            }else{
                cout<<ans;
                return 0;
            }
        }else{
            cout<<ans;
            return 0;
        }
    }else{
        cout<<ans;
        return 0;
    }
    cout<<ans;
    return 0;
}
