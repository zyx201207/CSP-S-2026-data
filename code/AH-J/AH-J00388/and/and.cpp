#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
//注意先审题，再写，不要死磕，不要用复杂算法,记得释放注释检查
//Chinese Can Fly
int n,m;
vector<int> a;
int ans=0;

void dfs(int now,int cnt,int cmp)
{
    if(cnt==m){ans=max(ans,cmp);return;}
    if(now>n)return;
    dfs(now+1,cnt+1,cmp&a[now]);
    dfs(now+1,cnt,cmp);
}
void solve1()
{
    dfs(1,0,pow(2,22)-1);
}
void solve2()
{
    for(int i=1;i<=n;i++)ans=max(ans,a[i]);
}
void solve3()
{
    ans=a[1];
    for(int i=1;i<=n;i++)ans&=a[i];
}
void solve4()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            ans=max(ans,a[i]&a[j]);
        }
    }
}
bool checkA()
{
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=a[i];k*=2)
        {
            if(!(a[i]&k))return false;
        }
    }
    return true;
}
void solve5()
{
    sort(a.begin()+1,a.end(),greater<int>());
    ans=a[m];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    a.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(n<=20)solve1();
    else if(m==1)solve2();
    else if(m==n)solve3();
    else if(m==2)solve4();
    else if(checkA())solve5();
    cout << ans;
    return 0;
}
