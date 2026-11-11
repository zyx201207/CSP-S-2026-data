#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int ans1,ans2,ans3,ans4;
bool a=false;



int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        ans1=1;
        if(s1[1]==s2[1]&&s1[0]==s2[0]){
            ans2=1;
            if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&c2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
                ans3=1;
                a=true;
            }
            else ans3=0;

            if(a&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
                ans4=1;
            }
            else ans4=0;
        }
        else ans2=0;
    }
    else{
        ans1=0;
    }

    cout << ans1 << ans2 << ans3 << ans4;
    return 0;

}
