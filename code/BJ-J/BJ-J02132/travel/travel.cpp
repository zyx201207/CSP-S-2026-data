#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int string2int(string str)
{
    int ret=0;
    for(int i=0;i<str.size();i++)
    {
        ret*=10;
        ret+=str[i]-'0';
    }
    return ret;
}
bool checkce()//判断是否在同一节车厢的同一排，且位于过道的同一侧
{
    return ((s1[2]<='C'&&s2[2]<='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'));
}
bool checklin()
{
    return (abs(s2[2]-s1[2])==1||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'));
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >>c1>>s1>>c2>>s2;
    int cx1=string2int(c1);//车厢编号
    int cx2=string2int(c2);
    cout <<(cx1==cx2);//判断是否在同一个车厢
    string st1=s1.substr(0,2);//排号
    string st2=s2.substr(0,2);
    int zw1=string2int(st1);
    int zw2=string2int(st2);
    cout <<(cx1==cx2&&zw1==zw2);//判断是否在同一车厢的同一排
    cout <<(cx1==cx2&&zw1==zw2&&checkce());
    cout <<(cx1==cx2&&zw1==zw2&&checkce()&&checklin());
    return 0;
}
