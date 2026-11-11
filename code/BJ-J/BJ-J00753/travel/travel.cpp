#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int flag1=1,flag2=1,flag3=1,flag4=1;//flag1判断第一个问题，后面以此类推
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>c1>>s1>>c2>>s2;
    //两张车票对应的座位是否在同一节车厢
    for(int i=0;i<c1.size();++i)
    {
        if(c1[i]!=c2[i])
        {
            flag1=0;
            break;
        }
    }
    //两张车票对应的座位是否在同一节车厢的同一排
    if(flag1)
    {
        for(int i=0;i<s1.size()-1;++i)
        {
            if(s1[i]!=s2[i])
            {
                flag2=0;
            }
        }
    }
    else
    {
        flag2=0;
    }
    //两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧
    if(flag2)
    {
        char t1=s1[2],t2=s2[2];
        if( !( ( (t1>='A' && t1<='C') && (t2>='A' && t2<='C') ) || ( (t1=='D' && t2=='F') || (t1=='F' && t2=='D') ) ) )
        {
            flag3=0;
        }
    }
    else
    {
        flag3=0;
    }
    //两张车票对应的座位是否相邻
    if(flag3)
    {
        int pos1=int(s1[2]);
        int pos2=int(s2[2]);
        char t1=s1[2],t2=s2[2];
        if( !( ( abs(pos1-pos2)==1 ) || ( (t1=='D' && t2=='F') || (t1=='F' && t2=='D') ) ) )
        {
            flag4=0;
        }
    }
    else
    {
        flag4=0;
    }
    cout<<flag1<<flag2<<flag3<<flag4;
    return 0;
}
