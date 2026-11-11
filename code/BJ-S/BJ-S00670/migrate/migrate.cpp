#include <bits/stdc++.h>
using namespace std;
int a[200010];
int ch[200010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--)
    {
        memset(ch,0,sizeof(ch));
        int n,d;
        scanf("%d%d",&n,&d);
        for(int i=1;i <= n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=2;i <= n;i++)
        {
            ch[i]=a[i]-a[i-1];
        }
        vector<int>v;
        v.push_back(0);
        long long sum=0;
        int cnt=0;
        for(int i=2;i <= n;i++)
        {
            if(ch[i-1]+ch[i]<=d&&ch[i-1]+ch[i]+ch[i+1]>d)
            {
                v.push_back(i-2);
                cnt++;
            }
        }
        if(ch[n-1]+ch[n]<=d)
        {
            v.push_back(n-2);
            cnt++;
        }
        if(cnt<2)
        {
            printf("0\n");
            continue;
        }
        for(int i=1;i < v.size()-1;i++)
        {
            long long ans=v[i]-v[i-1];
            long long ans1=v[i+1]-v[i];
            sum+=ans*ans1;
        }
        printf("%lld\n",sum);
    }
    return 0;
}