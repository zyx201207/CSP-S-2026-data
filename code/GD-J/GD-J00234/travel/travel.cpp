#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int cxa,cxb,pa,pb;
    char za,zb;
    bool tc=false,tp=false,xl=false;
    scanf("%d%d%c%d%d%c",&cxa,&pa,&za,&cxb,&pb,&zb);
    if(cxa==cxb)
    {
        printf("1");
        tc=true;
    }
    else printf("0");
    if(pa==pb && tc)
    {
        printf("1");
        tp=true;
    }
    else printf("0");
    if(tp && tc && ((za=='A' || za=='B' || za=='C') && (zb=='A' || zb=='B' || zb=='C')) || (za=='D' || za=='F') && (zb=='D' || zb=='F'))
        printf("1");
    else printf("0");
    bool a[5]={};
    char z[5]={'A','B','C','D','F'};
    for(int i=0;i<5;i++)
    {
        if(za==z[i] || zb==z[i])a[i]=true;
    }
    for(int i=0;i<4;i++)
    {
        if(a[i]==true && a[i+1]==true)
        {
            xl=true;
            break;
        }
    }
    if(a[2]==true && a[3]==true)xl=false;
    if(tc && tp && xl)printf("1");
    else printf("0");
    return 0;
}
