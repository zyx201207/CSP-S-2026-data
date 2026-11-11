#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2)cout << "0000";
    else if(s1[0] != s2[0] || s1[1] != s2[1])cout << "1000";
    else if((s1[2] <= 'C' && s2[2] >= 'D') || (s1[2] >= 'D' && s2[2] <= 'C'))cout << "1100";
    else if((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' || s1[2] == 'A'))cout << "1110";
    else cout << "1111";
    return 0;
}
/*
走吧 就算无法让大雨停下
还有我陪你在雨里放肆奔跑啊
地球上 天空下 我们做一对傻瓜
你我生来命中注定天真而伟大
*/