#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans1,ans2,ans3,ans4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans1=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            ans2=1;
            int tmp1=s1[2]-'A',tmp2=s2[2]-'A';
            if(s1[2]=='F') tmp1=4;
            if(s2[2]=='F') tmp2=4;
            if(tmp1>=0&&tmp1<=2&&tmp2>=0&&tmp2<=2||tmp1>=3&&tmp1<=4&&tmp2>=3&&tmp2<=4){
                ans3=1;
                if(tmp1==tmp2+1||tmp1==tmp2-1) ans4=1;
                else ans4=0;
            }
            else ans3=0;

        }
        else ans2=0;
    }
    else ans1=0;
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
