#include<bits/stdc++.h>
using namespace std;
int num[114514191];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    long long cnt;
    if(m==1)
    {
        int max114=-1073741829;
        for(int i=1;i<=n;i++)
        {
            max114=max(num[i],max114);
        }
        cout<<max114;
        return 0;
    }
    if(m==n)
    {
        cnt=num[1];
        for(int i=2;i<=n;i++)
        {
            cnt=cnt&num[i];
        }
        cout<<cnt;
        return 0;
    }
    if(m==n-1)
    {

        sort(num+1,num+n+1);
        cnt=num[2];
        for(int i=3;i<=n;i++)
        {
            cnt=cnt&num[i];
        }
        cout<<cnt;
        return 0;
    }
    if(m==2)
    {
        sort(num+1,num+n+1);
        cout<<num[n-1];
    }
    sort(num+1,num+n+1);
    cout<<num[n+1-m];
    return 0;
}
//tou wan fen shui jiao neng yi deng jiu xing
