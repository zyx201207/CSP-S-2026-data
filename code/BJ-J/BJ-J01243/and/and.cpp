#include <bits/stdc++.h>
using namespace std;
string ch (int a)
{
    string s="";
    while (a)
    {
        if (a%2==0){
            s+='0';
        }
        else s+='1';
        a/=2;
    }
    return s;
}
int he (string s1,string s2)
{
    int c=1,sum=0;
    for (int i=0;i<=max(s1.size(),s2.size())-1;i++)
    {
        if (s1[i]=='1' && s2[i]=='1')
        {
            sum+=c;
        }
        c*=2;
    }
    return sum;
}
int numm(string s)
{
    int ans;
    for (int i=0;i<s.size();i++)
    {

        if (s[i]=='1') ans++;
    }
    return ans;
}
struct stu {
    int a;
    string s;
    int num;
}q[1000000];
bool cmp(stu a ,stu b)
{
    if (a.num!=b.num){
        return a.num>b.num;
    }
    else{
        return a.a>b.a;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >>n>>m;
    int maxn=-1111;
    for (int i=1;i<=n;i++)
    {
        cin >> q[i].a;
        q[i].s=ch(q[i].a);
        q[i].num=numm(q[i].s);
        maxn=max(maxn,q[i].a);
    }
    sort (q+1,q+n+1,cmp);
    int all=0;
    string che=q[1].s;
    for (int i=2;i<=m;i++)
    {
        all=he(che,q[i].s);
        che=ch(all);
    }
    if (m==1) cout<<maxn;
    else cout<<all;
    return 0;
}
