#include <bits/stdc++.h>
using namespace std;
long long n, d, c, t, x[2000005], y[2000005];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        long long ans=0, s, b=0, o=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];y[x[i]]=i;
            if(!s) s=x[i]-x[i-1];
            if(s!=x[i]-x[i-1]) b=1;
        }if(!b) o=x[n]-x[n-1];
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                long long p=1, k=0, l=0;
                priority_queue<long long> q;
                while(p!=x[j])
                {
                    if(p+d<x[j])
                    {p=*(lower_bound(x+i, x+j+1, p)-1);
                    if(!l)l=y[p];}
                    else p=x[j],k++, l=j;
                    q.push(x[l-1]-x[l]);
                }
                if(k==1) continue;
                if(k==2)
                {
                    if(!b && 2*p/o-1==l-i) ans++;
                    else{p=*lower_bound(x+i, x+j+1, j-p);
                    if(l-y[p]+1==2) ans++;}
                }

            }

        }
        cout<<ans<<"\n";
    }
    return 0;
}
