#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[2000005];
int sum,num;
int n,d;

void chk(int step,int zhongdian,int numm)
{
    if (step==zhongdian)
    {
        if (numm<num)
        {
            num=numm;
            sum=1;
        }
        else if (numm==num) sum++;
        return;
    }
    for (int i=step+1;a[i]-a[step]<=d && i<=zhongdian;i++)
        chk(i,zhongdian,numm+1);
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin >> c >> t;
    if (c==11 || c==12)
    {
        while (t--)
        {
            cin >> n >> d;
            for (int i=1;i<=n;i++)
                cin >> a[i];
            if (d<2*(a[2]-a[1])) cout << 0 << endl;
            else
            {
                if (d<3*(a[2]-a[1]))
                {
                    int shu=d/(a[2]-a[1]);
                    cout << max(0ll,n-shu-1) << endl;
                }
                else
                {
                    int shu=(d/(a[2]-a[1]))*2;
                    //cout << "&&&" << shu << endl;
                    cout << max(0ll,n-shu+1) << endl;
                }
            }
        }
    }
    else if (c>=13 && c<=18)
    {
        while (t--)
            cout << 0 << endl;
    }
    else
    {
        while (t--)
        {
            cin >> n >> d;
            for (int i=1;i<=n;i++)
                cin >> a[i];
            int ans=0;
            for (int i=1;i<=n;i++)
                for (int j=i+1;j<=n;j++)
                {
                    num=4e18;
                    sum=0;
                    chk(i,j,0);
                    if (sum==2)
                    {
                        ans++;
                        //cout << "&&&" << i << " " << j << " " << num << endl;
                    }
                }
            cout << ans << endl;
        }

    }

    return 0;
}
