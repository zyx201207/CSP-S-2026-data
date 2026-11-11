#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)putchar('1');
    else{
        puts("0000");
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])putchar('1');
    else{
        puts("000");
        return 0;
    }
    if(s1[2]>'C'&&s2[2]>'C'){
        puts("11");
        return 0;
    }
    if(s1[2]<'D'&&s2[2]<'D')putchar('1');
    else{
        puts("00");
        return 0;
    }
    if(abs(s1[2]-s2[2])==1)putchar('1');
    else putchar('0');
    return 0;
}
