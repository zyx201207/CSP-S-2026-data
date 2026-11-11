#include <bits/stdc++.h>
using namespace std;
long long a[5007],n,t,c,d;
long long lst[5007][5007],cnt[5007][5007];
void floyed()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                //int i=4,j=1,k=2;
                if(lst[j][i]>lst[i][k]+lst[j][k])
                {
                    //cout << 1;
                    lst[i][j]=lst[j][i]=lst[i][k]+lst[j][k];
                    cnt[i][j]=cnt[j][i]=0;
                }
                if(lst[j][i]==lst[i][k]+lst[j][k]) cnt[i][j]++,cnt[j][i]++;
                //cout << cnt[i][j] << "\n";
            }
        }
    }
}
void print()
{
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout << lst[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\n------------------------\n";
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(abs(a[j]-a[i])<=d)
                {
                    //cout << i << " xx " << j << "\n";
                    lst[i][j]=lst[j][i]=1;//abs(a[j]-a[i]);
                }
                else lst[i][j]=lst[j][i]=1e18;
                if(i==j)
                {
                    lst[i][j]=lst[j][i]=0;
                    //cout << i << " " << j << "\n";
                }
                //print();
            }
            //print();
        }
        //print();
        floyed();
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                //cout << cnt[i][j] << " ";
                if(cnt[i][j]-1==2) ans++;
                cnt[i][j]=cnt[j][i]=0;
            }
            //cout << endl;
        }
        cout << ans << "\n";
    }
    return 0;
}
