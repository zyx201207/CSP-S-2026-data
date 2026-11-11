#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[3355306],dc[3355306],dcd[3355306],dcf[3355306],dcs[3355306],ans,id,ids,cy,cyy;
ll ansdd,anszc,ansdc;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);

    if(m==0)
    {
        ll kokp=0;
        for(ll i=2;i<=n;i++)
        {
            if(a[i]==a[i-1])kokp++;
            else
            {
                ans=max(ans,kokp+1);
                kokp=0;
            }
        }
        cout<<ans;
        return 0;
    }//zero

    ll opoo=abs(a[2]-a[1]),fll=1;
    for(ll i=3;i<=n;i++)if(a[i]-a[i-1]!=opoo)fll=2;
    if(fll==1)
    {
        ll dcm=m;
        for(ll i=opoo;;i+=opoo)
        {
            if(dcm<=0)break;
            if(dcm-i*2>=0)dcm=dcm-i*2,ansdc+=2;
            else if(dcm-i>=0)dcm=dcm-i,ansdc++;
            else break;
        }
        ansdc++;
    }//dc

    ll xxxx=0;
    for(ll i=1;i<=n;i++)
    {
        if(a[i]==a[i+1])xxxx++;
        else
        {
            xxxx++;
            if(xxxx>cy)cyy=a[i];
            cy=max(xxxx,cy);
            xxxx=0;
        }
    }
    if(cy>1)
    {
        for(ll i=1;i<=n;i++)dcd[i]=abs(cyy-a[i]);
        sort(dcd+1,dcd+n+1);
        ll didd=m;
        for(ll i=1;i<=n;i++)
        {
            if(didd<=0)break;
            if(dcd[i]==0)continue;
            if(didd-dcd[i]>=0)didd-=dcd[i];
            else break;
            ansdd++;
        }
        ansdd+=cy;
    }//dd

    if(n%2!=0)
    {
        id=n/2+1;
        for(ll i=1;i<=n;i++)dc[i]=abs(a[id]-a[i]);
        sort(dc+1,dc+n+1);
        ll di=m,szzc=0;
        for(ll i=1;i<=n;i++)
        {
            if(di<=0)break;
            if(dc[i]==0)
            {
                szzc++;
                continue;
            }
            if(di-dc[i]>=0)di-=dc[i];
            else break;
            anszc++;
        }
        anszc+=szzc;
    }
    else
    {
        id=n/2,ids=n/2+1;
        for(ll i=1;i<=n;i++)
        {
            dcf[i]=abs(a[id]-a[i]);
            dcs[i]=abs(a[ids]-a[i]);
        }
        sort(dcf+1,dcf+n+1);
        sort(dcs+1,dcs+n+1);
        ll xxf=m,xxs=m,ansf=0,anss=0,szf=0,szs=0;
        for(ll i=1;i<=n;i++)
        {
            if(xxf<=0)break;
            if(dcf[i]==0)
            {
                szf++;
                continue;
            }
            if(xxf-dcf[i]>=0)xxf-=dcf[i];
            else break;
            ansf++;
        }
        for(ll i=1;i<=n;i++)
        {
            if(xxs<=0)break;
            if(dcs[i]==0)
            {
                szs++;
                continue;
            }
            if(xxs-dcs[i]>=0)xxs-=dcs[i];
            else break;
            anss++;
        }
        anszc=max(ansf+szf,anss+szs);
    }//zcjo

    //cout<<anszc<<' '<<ansdd<<' '<<ansdc<<"\n";

    if(anszc>=ansdd&&anszc>=ansdc)ans=anszc;
    else if(ansdd>=anszc&&ansdd>=ansdc)ans=ansdd;
    else ans=ansdc;
    cout<<ans;
    return 0;
}//green or yellow   em mm
//NO Accepted
//Don't answer.
