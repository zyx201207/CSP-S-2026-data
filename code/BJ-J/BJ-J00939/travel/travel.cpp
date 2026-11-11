#include <bits/stdc++.h>
using namespace std;
#define ll long long
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    bool ans1=(c1==c2);
    bool ans2=(ans1&&s1[0]==s2[0]&&s1[1]==s2[1]);
    bool ans3=(ans2&&(s1[2]<'D'&&s2[2]<'D'||s1[2]>'C'&&s2[2]>'C'));
    bool ans4=(ans3&&(abs(s1[2]-s2[2])==1||s1[2]=='D'||s2[2]=='D'));
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
