#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=5e5+10;
int a[N];
bool A=1,B=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int cha=a[2]-a[1];
    for(int i=1;i<n;i++)
    {
        if(a[i+1]-a[i]!=cha)B=0;
        if(a[i]!=i)A=0;
    }
    if(A==1)
    {
        int sum=1;
        int cnt=1;
        while(sum<=m&&cnt<=n)
        {
            cnt++;
            sum+=sum+1;
        }
        cout<<cnt;
        return 0;
    }
    if(B==1)
    {
        int sum=cha;
        int cnt=1;
        while(sum<=m&&cnt<=n)
        {
            cnt++;
            sum+=sum+cha;
        }
        cnt-=1;
        cout<<cnt;
        return 0;
    }
    int maxn=-1;
    for(int i=1;i<=n;i++)
    {
        int jzx=a[i];
        int cnt=0;
        int num=0;
        for(int j=i;j>0;j--)
        {
            if(num>m)
            {
                cnt--;
                //num-=jzx-a[j];
                break;
            }
            num+=jzx-a[j];
            cnt++;
        }
        //cout<<i<<" "<<num<<endl;
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}
