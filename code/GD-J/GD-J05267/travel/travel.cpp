#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int  side1=0;
    if(s1[2]=='F'||s1[2]=='D')side1++;
    if(s2[2]=='F'||s2[2]=='D')side1++;
    int ans1=0,ans2=0,ans3=0,ans4=0;
    if(c1==c2){
        ans1=1;
        if(s1[1]==s2[1]&&s1[0]==s2[0]){
            ans2=1;
            if(side1%2==0){
                ans3=1;
                if(side1==2||s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
                    ans4=1;
                }
            }
        }
    }
    cout<<ans1<<ans2<<ans3<<ans4;

    return 0;
}
