#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else
    {
        cout<<0<<0<<0<<0<<endl;
        return 0;
    }
    string subs1=s1.substr(0,2);
    string subs2=s2.substr(0,2);
    if(subs1==subs2)cout<<1;
    else
    {
        cout<<0<<0<<0<<endl;
        return 0;
    }
    bool flag=false;
    if('A'<=s1[2]&&s1[2]<='C')
    {
        if('D'<=s2[2]&&s2[2]<='E')flag=false;
        else flag=true;
    }
    else
    {

        if('D'<=s2[2]&&s2[2]<='E')flag=true;
        else flag=false;
    }
    if(flag)cout<<1;
    else
    {
        cout<<0<<0<<endl;
        return 0;
    }
    if(abs(s1[2]-s2[2])==1)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<0<<endl;
        return 0;
    }
    return 0;
}
/*
现在是10.31 10:58,还有62分钟考试结束
我四道题都写完了希望AK（PPPPP）
下午s组会不会要炸
盲猜csp-s第一题构造
再见whk你好whk
自知之明PPPPPPPPPPPPPPPPPPPP
《课文大乱炖》PPPP
我常常追忆过去。PP
身段的大小色素的配合一切都是那么适宜。PPPP
白日依山尽，月下飞天镜，念桥边红药，鹅，饿，额。
渐入P境AKAKAKAKAKPAKAKAKAKAKAKAKAKAKPAKAKPAKPAKAKPPAKPAKPPPPPAKPPPPPAKAKPPKAPPPPPPPAKPPPPPPPAKPPPPPPPPPPPPPPPPPPPPPP
如果AK我将晴空一和排云上编印事情到比小
都怪输入法
如果J1我将笑成泪人
默写A+B problem:
#include<bits/stdc++.h>
using namespace stdl
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
    return 0;
}
想什么呢我没那么P话

“居然超过了short!"----A+B problem题解之一
”.....是蓝，高精除是紫，为什么这道题是红！“----出处同上
PPPP
P  P
P  P
PPPP

巍安格锤兵～马非～巍峨安格陈品～麻烦～


打表过a+b,打表过线段树，打表过cspj，打表过cpss，打表过noip,打表过noi,打表过ioi

英语翻译P语：I AK IOI
参考答案：|A|<|0|
读法：A的绝对值小于0的绝对值
P语言读法：IAKIOI



*/
