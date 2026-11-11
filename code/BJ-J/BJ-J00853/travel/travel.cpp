#include<bits/stdc++.h>
using namespace std;
int h[100];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    bool flag1=0,flag2=0,flag3=0,flag4=0;
    if(a==c) flag1=1;
    string x,y;
    for(int i=0;i<2;i++)
    {
        x+=b[i];
        y+=d[i];
    }
    h[65]=1;//a
    h[66]=2;//b
    h[67]=3;//c
    h[68]=5;//d
    h[70]=6;//f
    if(x==y&&flag1) flag2=1;
    if((h[b[2]]<=3&&h[d[2]]<=3||h[b[2]]>=5&&h[d[2]]>=5)&&flag2) flag3=1;
    if(flag3&&abs(h[b[2]]-h[d[2]])==1) flag4=1;
    cout<<flag1<<flag2<<flag3<<flag4;
    return 0;
}
