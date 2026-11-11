// #include<bits/stdc++.h>
// #define ll long long 
// using namespace std;
// int c;
// ll m;
// ll ans=0;
// int w[500050];
// struct zs
// {
//     int s;
//     int sj;
// }b[500050][500050];
// struct node
// {
//     int x;
//     int y;
// }a[500050];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     // freopen("subway.in","r",stdin);
//     // freopen("subway.out","w",stdout);
//     int n;
//     int d,q;
//     cin>>c>>n>>m>>d>>q;
//     for(int i=1;i<=m;i++)
//         cin>>w[i];
//     for(int i=1;i<=n;i++)
//     {
//         int z;
//         cin>>z;
//         for(int j=1;j<=z;j++)
//             cin>>b[i][j].s>>b[i][j].sj;
//     }
//     for(int i=1;i<=q;i++)
//         cin>>a[i].x>>a[i].y;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             int mm=1;
//             if(mm<=q)
//             {
//                 if(b[i][j].s==a[mm].x)
//                 {
//                     ans+=w[i];
//                     ans+=b[i][j].sj;
//                 }
//             }
//             mm++;
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// ll c,n,m,d,q;
// int a[500050];
// int b[500050];
// struct node
// {
//     int aa;
//     int bb;
// }c[500050];
// struct zs
// {
//     int x;
//     int y;
// }t[500050];
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     // freopen("subway.in","r",stdin);
//     // freopen("subway.out","w",stdout);
//     cin>>c>>n>>m>>d>>q;
//     ll ans=0;
//     for(int i=1;i<=m;i++)
//     {
//         cin>>a[i];
//         ans+=a[i];
//     }
        
//     for(int i=1;i<=n;i++)
//     {
//         cin>>b[i];
//         for(int j=1;j<=b[i];j++)
//         {
//             cin>>c[j].aa>>c[j].bb;
//             ans+=c[j].bb;
//         }
//     }
//     for(int i=1;i<=q;i++)
//     {
//         cin>>t[i].x>>t[i].y;
//     }
//     cout<<ans<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int x[2000020];
int y[2000020][2000020];
int flag1[2000020];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        long long n,d;
        long long ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
                y[i][j]=x[j]-x[i];
            for(int j=i;j<n;j++)
            {
                if(y[i][j]<=d)
                {
                    flag1[i]++;
                }
                if(j<=flag1[i])
                {
                    ans+=flag1[j];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}