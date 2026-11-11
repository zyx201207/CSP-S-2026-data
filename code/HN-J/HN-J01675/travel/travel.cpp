/*

我仍然在，无人问津的阴雨霉湿之地
和着雨音，唱着卖不出去的歌曲

2025年，我无法参赛。
所以，今年，2026年，我将AK J组，以平我遗憾！
我的天啊怎么比24年还简单
*/
#include <bits/stdc++.h>
using namespace std;

string a,b,c,d;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c) cout<<"0000";
    else{
        cout<<1;
        if(b[0]!=d[0]||b[1]!=d[1]) cout<<"000";
        else{
            cout<<1;
            if((b[2]<='C'&&d[2]>'C')||(b[2]>'C'&&d[2]<='C')) cout<<"00";
            else{
				cout<<1;
				if(abs(d[2]-b[2])==1||(d[2]=='F'&&b[2]=='D')||(d[2]=='D'||b[2]=='F')) cout<<1;
				else cout<<0;
            }
        }
    }
    return 0;
}
