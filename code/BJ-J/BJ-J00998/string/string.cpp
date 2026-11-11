#include<bits/stdc++.h>
using namespace std;
const int M=200005;
typedef long long LL;
LL a[M];
char c[M];
LL c1[30],c2[30],c3[30],c4[30];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    if(sum%2==1)
    {
        LL cnt=sum/2+1;
        int weizhi1=0,weizhi2=0;
        for(int i=1;;i++)
        {
            if(cnt-a[i]<=0)
            {
                weizhi1=i;
                weizhi2=cnt;
                break;
            }
            cnt-=a[i];
        }
        for(int i=1;i<=weizhi1;i++)
        {
            if(i==weizhi1)
            {
                c1[c[i]-'a']+=weizhi2-1;
            }
            else
            {
                c1[c[i]-'a']+=a[i];
            }
        }
        for(int i=weizhi1;i<=n;i++)
        {
            if(i==weizhi1)
            {
                c2[c[i]-'a']+=a[i]-weizhi2;
            }
            else
            {
                c2[c[i]-'a']+=a[i];
            }
        }
        LL ans=0;
        for(int i=0;i<=25;i++)
        {
            if(c3[i]-c4[i]>0)
            {
                ans+=c3[i]-c4[i];
            }
        }
        cout<<ans<<"\n";
    }
    else
    {
        LL cnt=sum/2;
        int weizhi3=0,weizhi4=0;
        for(int i=1;;i++)
        {
            if(cnt-a[i]<=0)
            {
                weizhi3=i;
                weizhi4=cnt;
                break;
            }
            cnt-=a[i];
        }
        for(int i=1;i<=weizhi3;i++)
        {
            if(i==weizhi3)
            {
                c3[c[i]-'a']+=weizhi4;
            }
            else
            {
                c3[c[i]-'a']+=a[i];
            }
        }
        for(int i=weizhi3;i<=n;i++)
        {
            if(i==weizhi3)
            {
                c4[c[i]-'a']+=a[i]-weizhi4;
            }
            else
            {
                c4[c[i]-'a']+=a[i];
            }
        }
        LL ans=0;
        for(int i=0;i<=25;i++)
        {
            if(c3[i]-c4[i]>0)
            {
                ans+=c3[i]-c4[i];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}