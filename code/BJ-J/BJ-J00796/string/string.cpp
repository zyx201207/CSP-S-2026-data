#include<bits/stdc++.h>
using namespace std;
unsigned long long n,ai,zgs,zjs;
unsigned long long fbgs[200005];
unsigned long long qzh[200005],hzh[200005],ans;
char ci,zm1,zm2;
unsigned long long wz1,wz2;
char fbzm[200006];
long long ls;

bool sfxt(unsigned long long a)
{
    //char zm1,zm2;

    for(unsigned long long x=1; x<=n; x++)
    {
        if(qzh[x]>=a)
        {
            zm1=fbzm[x];
            wz1=fbgs[x]-(a-qzh[x-1])+1;
            //cout<<"wz1="<<x<<'\n';
            break;
        }

    }
    for(unsigned long long x=n; x>=1; x--)
    {
        if(hzh[x]>=a)
        {
            zm2=fbzm[x];
            wz2=fbgs[x];
            //cout<<"wz2="<<wz2<<'\n';
            break;
        }

    }
    if(zgs>90000000)
    {
        if(wz1>wz2)
        {
            ls=wz2;
        }
        else
        {
            ls=wz1;
        }

    }
    else
    {
        ls=1;
    }

    //cout<<"ls="<<ls<<'\n';
    if(zm1==zm2)
    {
        return 1;
    }
    else
    {
        //cout<<0<<' '<<a<<' '<<int(zm1)<<' '<<int(zm2)<<' '<<zgs<<endl;
        return 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(unsigned long long i=1; i<=n; i++)
    {
        cin>>ai>>ci;
        zgs+=ai;
        fbzm[i]=ci;
        fbgs[i]=ai;
        qzh[i]=ai+qzh[i-1];
    }
    for(unsigned long long i=n; i>=1; i--)
    {
        hzh[i]=fbgs[i]+hzh[i+1];
        //cout<<hzh[i]<<'g'<<fbgs[i]<<'g'<<hzh[i+1]<<' ';
    }
    //cout<<'\n'<<'\n';
    zjs=zgs/2;
    for(unsigned long long j=1; j<=zjs; j++)
    {
        //long long ls;
        /*
        if(fbgs[j]>fbgs[(n-j)+1]){
            ls=fbgs[(n-j)+1];
        }else{
            ls=fbgs[j];
        }
        */

        if(sfxt(j)==1)
        {


            //cout<<1<<' '<<j<<zm1<<zm2<<endl;
        }
        else
        {
            //cout<<0<<' '<<j<<zm1<<zm2<<endl;
            if(ls>0)ans+=ls;
            else  ans++;
            //return 0;

        }
        j+=ls;
        if(ls>0)j--;
        //cout<<"ans="<<ans<<' ';
        //cout<<"ls="<<ls<<'\n';
    }
    cout<<ans;
    return 0;
}
