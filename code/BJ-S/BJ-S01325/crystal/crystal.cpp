#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long maxa=0;
long long mina=1000000000005;
long long akk[200005];
long long pd(long long k,long long m)
{
    long long anss=0;
    long long an=0;
    long long ak[200005];
    for(long long i=1;i<=n;i++)
    {
        if(a[i]>k)
        {
            continue;
        }
        ak[i]=k-a[i];
        an++;
    }
    sort(ak+1,ak+an+1);
    long long km=1;
    while((m-ak[km])>=0&&km<=an)
    {
        m=m-ak[km];
        km++;
        anss++;
    }
    return anss;

}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long fleg=0;

    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        maxa=max(maxa,a[i]);
        mina=min(mina,a[i]);
        if(i>=2&&a[i-1]+1!=a[i])
        {
            fleg=11;
        }
        if(i>=2)
        {
            akk[i-1]=a[i]-a[i-1];
        }

    }
    long long ansss=0;
    if(fleg==0&&fleg!=1)
    {

        //for(long long i=1;i<maxa;i++)
        //{
         //   m=m-i;
        //    if(m>=0)
        //    {
        //        ansss++;
         //   }
         //   else
          //  {
          //      break;
           // }
        //}
        //cout<<ansss+1;
        long long aaa=1+8*m;
        ansss=(-1+sqrt(aaa))/2;
        cout<<ansss+1;
        //fclose(stdin);
        //fclose(stdout);
        return 0;
    }
    long long akkk=0;
    for(long long i=2;i<n;i++)
    {
        if(akk[i]!=akk[i-1])
        {
            fleg=7;
            break;
        }
        else
        {
            fleg=3;
            akkk=akk[i];

        }
    }
    if(fleg==3)
    {
        long long bbb=akkk*akkk+8*akkk*m;

        ansss=(-akkk+sqrt(bbb))/(2*akkk);


        cout<<ansss+1;
        //fclose(stdin);
        //fclose(stdout);
        return 0;

    }
    long long l=mina;
    long long r=maxa;
    long long ans=0;
    for(long long i=mina;i<=maxa;i++)
    {
        ans=max(ans,pd(i,m));

    }
    cout<<ans;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
