#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long n,m,ans;
string a;
pair <long long,char> p[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long x;
        char y;
        cin>>x>>y;
        if(y==p[m].second) p[m].first+=x;
        else p[++m].first=x,p[m].second=y;
    }
    if(n<=2000)
    {
        int cnt=0;
        for(int i=1;i<=m;i++) for(int j=1;j<=p[i].first;j++) cnt++,a+=p[i].second;
        for(int i=1;i<=(cnt/2);i++)
        {
            if(a[i]!=a[cnt-i+1]) ans++;
        }
        cout<<ans<<endl;
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            long long cnt=p[i].first;
            while(p[m+i-1].first<=cnt)
            {
                cnt-=p[m+i-1].first;
                if(p[i].second!=p[m+i-1].second) ans+=p[m-i+1].first;
                m--;
            }
            p[m+i-1].first-=cnt;
            if(p[i].second!=p[m+i-1].second) ans+=cnt;
            m--;
        }
        cout<<ans;
    }
    return 0;
}
