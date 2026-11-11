#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
long long pre[N];
long long suf[N];
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long m1,m2,t=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&pre[i]);
        t+=pre[i];
        suf[i]=pre[i];
        cin>>c[i];
    }
    //cout<<t/2<<endl;
    for(int i=n;i>=1;i--)
    {
        suf[i]+=suf[i+1];
        //cout<<suf[i]<<" ";
    }
    //cout<<endl;
    for(int i=n;i>=1;i--)
    {
        if(suf[i]>=t/2)
        {
            m2=i;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        pre[i]+=pre[i-1];
        //cout<<pre[i]<<" ";
    }
    //cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(pre[i]>=t/2)
        {
            m1=i;
            break;
        }
    }
    //cout<<m1<<" "<<m2<<endl;
    pre[m1]=suf[m2]=t/2;
    long long cnt=0;
    long long b1=1,b2=1;
    //long long cur=0;
    /*while(b1<=m1&&b2<=m2)
    {
        long long x=min(pre[b1]-cur,suf[b2]-cur);
        if(c[b1]!=c[n-b2+1])
            cnt+=x;
        cur+=x;
        //cout<<cur<<endl;
        if(pre[b1]<=suf[b2])
            b1++;
        if(suf[b2]<=pre[b1])
            b2++;
    }*/
    //cnt=0;
    //b1=b2=1;
    for(long long i=1;i<=t/2;i++)
    {
        if(i>=pre[b1])
            b1++;
        if(i>=suf[b2])
            b2++;
        if(c[b1]!=c[n-b2+1])
            cnt++;
    }
    printf("%lld\n",cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
