#include<bits/stdc++.h>
char c1,c2;
int i1,i2,i3,i4;
std::string s1,s2,s3,s4;
int s2i(std::string s)
{
    int tmp=0;
    for(char x:s)
    {
        if(isdigit(x))
        {
            tmp*=10;
            tmp+=x-'0';
        }
    }
    return tmp;
}
bool check1(char c1,char c2)
{
    if(c1<'D'&&c2<'D'||c1>'C'&&c2>'C')
    {
        return true;
    }
    return false;
}
bool check2(char c1,char c2)
{
    if(abs(c1-c2)==1&&!(c1=='C'&&c2=='D'||c1=='D'&&c2=='C')||c1=='D'&&c2=='F'||c1=='F'&&c2=='D')
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    std::cin>>s1>>s2>>s3>>s4;
    c1=s2[s2.size()-1];
    c2=s4[s4.size()-1];
    i1=s2i(s1);
    i2=s2i(s2);
    i3=s2i(s3);
    i4=s2i(s4);
    std::cout<<(i1==i3)<<(i1==i3&&i2==i4)<<(i1==i3&&i2==i4&&check1(c1,c2))<<(i1==i3&&i2==i4&&check2(c1,c2));
    return 0;
}
