#include <bits/stdc++.h>
using namespace std;
bool ans[5];
int main(){
    //TODO: delete //
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c1, c2, s1, s2;
    cin>>c1>>s1>>c2>>s2;
    ans[1] = (c1==c2);
    ans[2] = (ans[1]&&s1[0]==s2[0]&&s1[1]==s2[1]);
    ans[3] = (ans[2]&&(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'));
    ans[4] = (ans[3]&&(abs(s1[2]-s2[2])==1));
    for(int i=1;i<=4;i++){
        cout<<ans[i]?'1': '0';
    }
    return 0;
}
