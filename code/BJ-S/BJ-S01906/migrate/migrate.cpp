#include<bits/stdc++.h>
using namespace std;
int tt,T;
int n;
long long d;
long long x[2000005];
int zz[2000005],zy[2000005];
int sum[2000005],l1[2000005],r1[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>tt>>T;
    int l,r,mid;
    long long ll,rr,ans;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            sum[i]=0;
            l1[i]=r1[i]=0;
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            l=1,r=i;
            while(l<r)
            {
                mid=(l+r)>>1;
                if(x[i]-x[mid]>d)
                {
                    l=mid+1;
                }else
                {
                    r=mid;
                }
            }
            zz[i]=l;
            l=i,r=n;
            while(l<r)
            {
                mid=(l+r+1)>>1;
                if(x[mid]-x[i]>d)
                {
                    r=mid-1;
                }else
                {
                    l=mid;
                }
            }
            zy[i]=l;
        }
        for(int i=1;i<=n;i++)
        {
            sum[i]=i-zz[i]+sum[zz[i]];
            if(zz[i]==i||zz[i]==i-1)continue;
            if(zz[zz[i]+1]==zz[zz[i]])sum[i]-=sum[zz[i]];
            else sum[i]-=zz[i]-zz[zz[i]+1];
        }
        /*for(int i=n;i;i--)
        {
            sum1[i]=zy[i]-i+sum1[zy[i]];
            if(zy[i]==i||zy[i]==i+1)continue;
            if(zy[zy[i]-1]==zy[zy[i]])sum1[i]-=sum1[zy[i]];
            else sum1[i]-=zy[zy[i]-1]-zy[i];
        }*/
        for(int i=1;i<=n;i++)
        {
            if(zz[i]==i)continue;
            if(zz[i]==i-1)
            {
                l1[i]=l1[i-1];
                r1[i]=r1[i-1];
                continue;
            }
            l1[i]=zz[zz[i]+1];
            if(zz[i]==i-2)r1[i]=zz[i]-1;
            else r1[i]=zz[zz[i]+2]-1;
            if(l1[i]>r1[i])l1[i]=r1[i]=0;
        }
        //for(int i=1;i<=n;i++)cout<<'('<<l1[i]<<' '<<r1[i]<<')';
        //cout<<'\n';
        /*for(int i=n;i;i--)
        {
            if(zy[i]==i)continue;
            if(zy[i]==i+1)
            {
                l2[i]=l2[i+1];
                r2[i]=r2[i+1];
                continue;
            }
            r2[i]=zy[zy[i]-1];
            if(zy[i]==i+2)l2[i]=zy[i]+1;
            else l2[i]=zy[zy[i]-2]+1;
        }
        for(int i=1;i<=n;i++)cout<<'('<<l2[i]<<' '<<r2[i]<<')';
        cout<<'\n';*/
        for(int i=1;i<=n;i++)
        {
            if(l1[i]>r1[i]||!l1[i])continue;
            if(zz[i]==i-1)
            {
                ans+=ll;
                continue;
            }
            int tmpr1=min(zz[zz[i]],r1[zz[i]]),tmpr2=min(zz[zz[i]],r1[zz[i]+1]),cnt,cnt1;
            cnt=max(tmpr1,tmpr2);
            /*tmpl1=max(i,l2[zz[i]]),tmpr1=max(i+sum[i],r2[zz[i]]),tmpl2=max(i,l2[zz[i]+1]),tmpr2=max(i+sum[i],r2[zz[i]+1]);
            if(tmpr1<tmpl2)
            {
                cnt=max(tmpr1-tmpl1+1,0)+max(tmpr2-tmpl2+1,0);
            }else
            {
                cnt=max(tmpr2-tmpl1+1,0);
            }*/
            if(zz[zz[i]]!=zz[zz[i]+1])
            {
                ll=r1[i]-l1[i]+1;
            }else
            {
                ll=r1[i]-l1[i]+1+min(zz[zz[i]]-cnt-1,sum[zz[zz[i]]]);
                //cout<<'('<<i<<' '<<zz[zz[i]]<<' '<<cnt<<' '<<zz[i]<<' '<<r1[zz[i]]<<' '<<r1[zz[i]+1]<<')';
            }
            ans+=ll;
        }
        cout<<ans<<'\n';
    }
}
