#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
int find1()
{
    if(a==c) return 1;
    else return 0;
}
int find2(int z)
{
    if(z==0) return 0;
    for(int i=0;i<b.size()-1;i++)
    {
        for(int j=0;j<d.size()-1;j++)
        if(b[i]!=d[j]&&i==j) return 0;
    }
    return 1;
}
int find3(int m)
{
    if(m==0) return 0;
    char x,y;
    x=b[b.size()-1];
    y=d[d.size()-1];
    if((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C')) return 1;
    else if((y=='D'||y=='F')&&(y=='D'||y=='F')) return 0;
    else return 0;
}
int find4(int y)
{
    if(y)
    {
        char t,k;
        t=b[b.size()-1];
        k=d[d.size()-1];
        if(t==k+1||t==k-1) return 1;
        else return 0;
    }
    else return 0;
}
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c>>d;
    int z=find1();
    int x=find2(z);
    int y=find3(x);
    cout<<z<<x<<y<<find4(y);
    return 0;
}
