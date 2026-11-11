#include<bits/stdc++.h>
using namespace std;
int sr(string a,string b)
{
    string temp1,temp2;
    for(int i=0;i<=1;i++)
    {
        temp1=a[i];
        temp2=b[i];
    }
    if(temp1==temp2) return 1;
    else return 0;
}

int ss(string a,string b)
{
    string temp1,temp2;
    for(int i=2;i<=2;i++)
    {
        temp1=a[i];
        temp2=b[i];
    }
    if(temp1=="A"||temp1=="B"||temp1=="C" && temp2=="A"||temp2=="B"||temp2=="C") return 1;
    else if(temp1=="D"||temp1=="F" && temp2=="D"||temp2=="F") return 1;
    else return 0;
}


int between(string a,string b)
{
    string temp1,temp2;
    for(int i=2;i<=2;i++)
    {
        temp1=a[i];
        temp2=b[i];
    }
    if(temp1=="A"&&temp2=="B" || temp1=="B"&&temp2=="C" || temp1=="D"&&temp2=="F") return 1;
    else if(temp1=="B"&&temp2=="A" || temp1=="C"&&temp2=="B" || temp1=="F"&&temp2=="D") return 1;
    else return 0;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2) cout<<1;
    else cout<<0;

    if(sr(s1,s2)==1) cout<<1;
    else cout<<0;

    if(ss(s1,s2)==1) cout<<1;
    else cout<<0;

    if(between(s1,s2)==1) cout<<1;
    else cout<<0;

    return 0;
}
