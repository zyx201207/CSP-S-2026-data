#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool flag1=1,flag2=1,flag3=1,flag4=1;
    flag1=(c1==c2);
    for(int i=0;i<2;i++)if(s1[i]!=s2[i])flag2=0;
    flag2&=flag1;
    if(s1[2]>s2[2])swap(s1,s2);
    flag3=1-('A'<=s1[2]&&s1[2]<='C'
           &&'D'<=s2[2]&&s2[2]<='F');
    flag3&=flag2;
    flag4=(s2[2]-s1[2]==1)&&flag3;
    cout << flag1 << flag2 << flag3 << flag4 << "\n";
    return 0;
}