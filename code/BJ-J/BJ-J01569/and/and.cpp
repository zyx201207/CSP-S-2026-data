#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;
struct numid
{
    int numof1,length,num;
    string turn_2_num;
    double num1_p;
}g[N];
string turn_2(int a)
{
    string s;
    while(a>0)
    {
        s+=a%2;
        a/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
bool cmp(numid a,numid b)
{
    if(a.length==b.length)
        return a.num1_p>b.num1_p;
    return a.length>b.length;
}
int n,m,ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>g[i].num;
        g[i].turn_2_num=turn_2(g[i].num);
        g[i].length=g[i].turn_2_num.length();
        for(int j=0;j<=g[i].length;j++)
            if(g[i].turn_2_num[j]=='1') g[i].numof1++;
        g[i].num1_p=g[i].numof1*1.0/g[i].length;
    }
    sort(g+1,g+n+1,cmp);
    ans=g[1].num&g[2].num;
    for(int i=2;i<=m-1;i++) ans=ans&g[i].num;
    cout<<ans;
    return 0;
}