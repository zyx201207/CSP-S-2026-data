#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n;
long long m;
long long t;
long long k;
long long v;
long long cnt;
long long ans;
int flag;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ans=0;
    cnt=1;
    if(n<10000)
    {

        for(int z=1;z<=n-1;z++)
        {
            cnt=1;
            v=m;
            if(n-z+1<ans)
            {
                break;
            }
            for(int i=z;i<=n-1;i++)
            {
                k=a[i+1]-a[i];
                k=k*i;
                if((v-k)>=0)
                {
                    v=v-k;
                    cnt++;
                //cout<<i<<" ";
                }
                else
                {
                    break;
                }
        }
        ans=max(ans,cnt);
        if(ans==n)
        {
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
    return 0;
    }
    else
    {
        flag=0;
        for(int i=2;i<=n-1;i++)
        {
            if((a[i]-a[i-1])!=(a[i+1]-a[i]))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            v=m;
            for(int i=1;i<=n-1;i++)
            {
                k=a[i+1]-a[i];
                k=k*i;
                if((v-k)>=0)
                {
                    v=v-k;
                    cnt++;
            //cout<<i<<" ";
                }
                else
                {
                    cout<<cnt;
                    return 0;
                }
            }
            cout<<cnt;
        }
        else
        {
            for(int z=1;z<=n-1;z++)
        {
            cnt=1;
            v=m;
            if(n-z+1<ans)
            {
                break;
            }
            for(int i=z;i<=n-1;i++)
            {
                k=a[i+1]-a[i];
                k=k*i;
                if((v-k)>=0)
                {
                    v=v-k;
                    cnt++;
                //cout<<i<<" ";
                }
                else
                {
                    break;
                }
        }
        ans=max(ans,cnt);
        if(ans==n)
        {
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
    return 0;
        }
    }
    return 0;
}
/*

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

6 6
1 1 1 1 1 1
*/
