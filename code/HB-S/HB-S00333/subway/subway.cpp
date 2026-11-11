#include<bits/stdc++.h>
using namespace std;
long long num[5000005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long n;
    long long m;
    int cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];

    }
    if(n>5000)
    {
        int qiuhe=0;
        for(int i=1;qiuhe<m;i++)
        {
            qiuhe+=num[i];
            cnt++;
        }
        cout<<cnt;
        return 0;
    }
    sort(num+1,num+1+n);

    long long mx=-2147483648;
    long long m1=m;
    for(long long i=1;i<=n;i++)
    {
        long long j=1;
        long long cnt=1;
        m1=m;
        while(num[i]-num[i-j]<=m1&&i-j>=1)
        {
            m1-=(num[i]-num[i-j]);
            cnt++;
            j++;
        }
        mx=max(mx,cnt);
    }
    cout<<mx<<endl;
    return 0;
}
