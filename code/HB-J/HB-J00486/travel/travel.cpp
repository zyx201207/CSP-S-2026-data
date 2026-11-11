#include<bits/stdc++.h>
using namespace std;
struct cx
{
    string cxh;
    string zwh;
};
int main()
{
    cx p1,p2;
    cin>>p1.cxh>>p1.zwh>>p2.cxh>>p2.zwh;
    string sc="";
    if(p1.cxh!=p2.cxh)
    {
        sc="0000";
    }else
    {
        sc=sc+"1";
        string s1,s2;
        s1=p1.zwh[0]+p1.zwh[1];
        s2=p2.zwh[0]+p2.zwh[1];
        if(s1==s2)
        {
            sc+="1";
            char c1=p1.zwh[2];
            char c2=p2.zwh[2];
            if((c1>='A'&&c1<='C'&&c2>='A'&&c2<='C')||(c1>='D'&&c1<='F'&&c2>='D'&&c2<='F'))
            {
                sc+="1";
                if(abs(c1-c2)==1)
                {
                    sc+="1";
                }else
                {
                    sc+="0";
                }
            }else
            {
                sc+="00";
            }
        }else
        {
            sc+="000";
        }
    }
    cout<<sc;
    return 0;
}
/*
• 两张车票对应的座位是否在同一节车厢;
• 两张车票对应的座位是否在同一节车厢的同一排;
• 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;
• 两张车票对应的座位是否相邻。
*/
