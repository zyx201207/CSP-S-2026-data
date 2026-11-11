#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1001000];
int bucket[1005]={0};
int n,m,flago=1,flagt=1,flagth=1;
void spec3()
{
    int ans=-1;
    for(int i=0;i<750;i++)
    {
       int nans=bucket[i];
       int mlft=m;
        if(bucket[i])
        {
            //cout<<"I "<<i<<endl;
            for(int j=i-1;j>0;j--)
            if (bucket[j])
            {
                 //cout<<"J "<<j<<" ";
                int dn=min(bucket[j],(int)mlft/(int)(i-j));
                if (dn<0)
                    dn=0;
                nans+=dn;
                //cout<<dn<<" ";
                mlft-=dn*(i-j);
                //cout<<mlft<<endl;
            }
        }
        ans=max(ans,nans);
    }
    cout<<ans;
}
void spec1()
{
    //cout<<"SPEC";
    int nans=0;
        int mleft=m;
        for (int j=n;j>0;j--)
        {
            if (mleft>=(a[n]-a[j]))
            {
                nans++;mleft-=(a[n]-a[j]);
            }
        }

    cout<<nans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=2;i++)
    {
        cin>>a[i];
        if(a[i]!=i)
            flago=0;
            if(abs(a[i])>200)
            flagth=0;
            else
            bucket[a[i]+200]++;
    }
    //cout<<"1111";
    for (int i=3;i<=n;i++)
    {
        cin>>a[i];
        if(abs(a[i])>200)
            flagth=0;
            else
            bucket[a[i]+200]++;
        if(a[i]!=i)
            flago=0;
            if((a[i]-a[i-1])!=(a[i-1]-a[i-2]))
            flagt=0;
    }
    //cout<<"11111";
    //cout<<flagt<<endl;
    if(flagth==1)
    {
        spec3();
        return 0;
    }
    if(flago==1)
    {
        spec1();
        return 0;
    }
    if (flagt==1)
    {
        if (a[2]-a[1]==0)
            cout<<n;
        else
        {
            //cout<<"SPEC2"<<endl;
            spec1();
        }
        return 0;
    }
    //cout<<"NORM";
    sort(a+1,a+n+1);
    int ans=-1;
    for (int i=1;i<=n;i++)
    {
        int nans=0;
        int mleft=m;
        for (int j=i;j>0;j--)
        {
            if (mleft>=(a[i]-a[j]))
            {
                nans++;mleft-=(a[i]-a[j]);
            }
            ans=max(ans,nans);
        }
    }
    cout<<ans;
    return 0;
    //zuo!
    //zuiganjingdeaosai!
    //I want to play Genshin Impact
}
