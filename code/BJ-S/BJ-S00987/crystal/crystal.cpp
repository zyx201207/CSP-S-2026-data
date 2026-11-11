#include <bits/stdc++.h>
using namespace std;
long long a[500007],sum,cnt,n,m,maxx,flag=1,flag2=1;
long long chk(long long n)
{
    sum=0,cnt=0;
    long long mid=a[n];
    for(long long i=n-1;i>=1;i--)
    {
        sum+=abs(a[i]-mid);
        //cout << sum << " " << cnt << "\n";
        if(sum>m) break;
        cnt++;
    }
    return cnt;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //long long n,m;
    cin >> n >> m;
    long long diff;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]!=i) flag=0;//subtaskA
        if(i==2) diff=a[2]-a[1];
        if(i>2&&a[i]-a[i-1]!=diff) flag2=0;//B
    }
    //cout << flag << " " << diff;
    if(flag)//subtaskA
    {
        long long i;
        for(i=1;i<=n;i++)
        {
            if((a[1]+a[i])*i/2>m) break;
        }
        cout << min(i,n) << "subA";
        return 0;
    }
    sort(a+1,a+n+1);
    if(flag2)//B
    {
        long long i;
        for(i=1;i<=n;i++)
        {
            if((a[1]+a[i])*i/2>m) break;
        }
        cout << min(i,n) << "subB";
        return 0;
    }
    //subtask1
    for(long long mid=1;mid<=n;mid++)
    {
        flag=0;
        maxx=max(chk(mid),maxx);
        //cout << l << " " << mid << " " << r << " " << chk(mid) << "\n";
    }
    cout << maxx+1;
    return 0;
}
