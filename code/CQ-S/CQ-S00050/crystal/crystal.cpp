#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n;
long long m,a[500001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    queue<int>q;
    long long nw=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        nw+=(a[i]-a[i-1])*q.size();
        while(nw>m)
        {
            nw-=a[i]-a[q.front()];
            q.pop();
        }
        q.push(i);
        cnt=max(cnt,int(q.size()));
    }
    cout<<cnt<<endl;
    return 0;
}
