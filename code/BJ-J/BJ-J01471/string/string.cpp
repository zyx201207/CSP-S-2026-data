#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
    int a;
    char c;
    long long left,right;
}charact[200005];
string sl,sr;
long long cnt,ans,pos,mid;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>charact[i].a>>charact[i].c;
        charact[i].left=cnt+1;
        cnt+=charact[i].a;
        charact[i].right=cnt;
    }
    if(cnt%2==0)
        mid=cnt/2;
    else
        mid=cnt/2+1;
    for(int i=1;i<=n;i++)
    {
        if(charact[i].left<=mid && charact[i].right>=mid)
        {
            pos=i;
            break;
        }
    }
    long long mul=0;
    for(int i=1;i<=pos;i++)
    {
        if(mul+charact[i].a>mid)
            for(int j=1;j<=mid-mul;j++)
            {
                 sl+=charact[i].c;
             }
         else
            for(int j=1;j<=charact[i].a;j++)
             {
                 sl+=charact[i].c;
             }
         mul+=charact[i].a;
    }
    mul=0;
    for(int i=n;i>=pos;i--)
    {
        if(mul+charact[i].a>mid)
            for(int j=1;j<=mid-mul;j++)
            {
                 sr+=charact[i].c;
             }
         else
            for(int j=1;j<=charact[i].a;j++)
             {
                 sr+=charact[i].c;
             }
         mul+=charact[i].a;;
    }
    for(int i=0;i<mid;i++)
    {
        if(sl[i]!=sr[i])
            ans++;
    }
    cout<<ans;
    return 0;
}
