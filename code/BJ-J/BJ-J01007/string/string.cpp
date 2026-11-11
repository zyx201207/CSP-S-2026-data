#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long ans,sum,x,y,hsum;
int n,k=1;
long long t1[N],a[N],cnt;
char t2[N],c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>t1[i]>>t2[i];
    for(int i=1;i<=n;i++)
        sum+=t1[i];
    hsum=sum/2+sum%2;
    if(sum%2)
    {
        long long t=0;
        for(int i=1;i<=n;i++)
        {
            t+=t1[i];
            if(t==hsum||t-t1[i]+1==hsum)a[++cnt]=t1[i]-1,c[cnt]=t2[i],hsum--,sum--;
            else if(t>hsum&&t-t1[i]<hsum)a[++cnt]=hsum-t+t1[i]-1,c[cnt]=t2[i],a[++cnt]=t-hsum,c[cnt]=t2[i],hsum--,sum--;
            else a[++cnt]=t1[i],c[cnt]=t2[i];
        }
    }
    else
    {
        long long t=0;
        for(int i=1;i<=n;i++)
        {
            t+=t1[i];
            if(t>hsum&&t-t1[i]<hsum)a[++cnt]=hsum-t+t1[i],c[cnt]=t2[i],a[++cnt]=t-hsum,c[cnt]=t2[i];
            else a[++cnt]=t1[i],c[cnt]=t2[i];
        }
    }
    x=a[1],y=a[cnt];
    for(long long l=1,r=cnt,ls=a[l],rs=a[r];ls<=hsum&&rs<=hsum&&l!=r;)
    {

        if(c[l]!=c[r])ans+=min(x,y);
        if(x>y)x-=y,r--,rs+=a[r],y=a[r];
        else if(x<y)y-=x,l++,ls+=a[l],x=a[l];
        else x=a[l],y=a[r],l++,r--,ls+=a[l],rs+=a[r];
    }
    printf("%lld",ans);
    return 0;
    fclose(stdin);
    fclose(stdout);
}
