//GZ-J00557 贵阳市南明区第一实验中学 夏泽轩
#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    bool ans1=(a==b);
    bool ans2=(ans1&&c[0]==d[0]&&c[1]==d[1]);
    bool ans3=(ans2&&!(c[2]=='C'&&d[2]=='D')&&!(c[2]=='D'&&d[2]=='C'));
    bool ans4=(ans3&&(c[2]=='D'||c[2]=='F'||abs(c[2]-d[2])==1));
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
