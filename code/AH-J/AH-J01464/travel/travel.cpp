#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c1,c2;
    bool ans1 = 0,ans2 = 0,ans3 = 0,ans4 = 0;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1 == c2) ans1 = 1;
    if(ans1&&(s1.substr(0,2) == s2.substr(0,2))) ans2 = 1;
    if(ans2){
        if((s1[2] == 'D'&&s2[2] == 'E')||(s1[2] == 'E'&&s2[2] == 'D')){
            ans3 = 1;
            ans4 = 1;
        }
        else if((s1[2] == 'A'||s1[2] == 'B'||s1[2] == 'C')&&(s2[2] == 'A'||s2[2] == 'B'||s2[2] == 'C')) ans3 = 1;
    }
    if(ans3&&((s1[2] == 'C'&&s2[2] == 'B')||(s2[2] == 'C'&&s1[2] == 'B'))) ans4 = 1;
    if(ans3&&((s1[2] == 'A'&&s2[2] == 'B')||(s2[2] == 'A'&&s1[2] == 'B'))) ans4 = 1;
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
/*

*/
//CCF please let me AC!
