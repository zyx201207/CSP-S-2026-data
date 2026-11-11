#include<bits/stdc++.h>
using namespace std;
long long n,num[200010];
long long sum[200010],len;
char c[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>num[i]>>c[i];
        sum[i]=sum[i-1]+num[i];
    }
    len=sum[n];
    long long h=len/2,idl,l,idr,r;
    if(len%2==0)
    {
        for(int i=1; i<=n; i++)
        {
            if(sum[i]==h)
            {
                idl=i;
                l=sum[i];
                r=sum[i]+1;
                idr=i+1;
                break;
            }
            if(sum[i]>h)
            {
                idl=i;
                l=h;
                r=h+1;
                idr=i;
                break;
            }
        }
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            if(sum[i]==h)
            {
                idl=i;
                l=sum[i];
                r=sum[i]+2;
                idr=i+1;
                break;
            }
            if(sum[i]>h)
            {
                idl=i;
                l=h;
                r=h+2;
                idr=i;
                break;
            }
        }
    }
    long long lastl=l-sum[idl-1],lastr=sum[idr]-r+1;
    long long ans=0;
    //cout<<l<<" "<<r<<" "<<lastl<<" "<<lastr<<endl;
    while(idl!=1||idr!=n||(lastl!=0&&lastr!=0))
    {
        if(c[idl]==c[idr])
        {
            if(lastl>lastr)
            {
                lastl-=lastr;
                if(idr!=n)
                {
                    idr++;
                    lastr=num[idr];
                }
            }
            else
            {
                lastr-=lastl;
                if(idl!=1)
                {
                    idl--;
                    lastl=num[idl];
                }
            }
        }
        else
        {
            if(lastl>lastr)
            {
                ans+=lastr;
                lastl-=lastr;
                if(idr!=n)
                {
                    idr++;
                    lastr=num[idr];
                }
            }
            else
            {
                ans+=lastl;
                lastr-=lastl;
                if(idl!=1)
                {
                    idl--;
                    lastl=num[idl];
                }
            }
        }
        //cout<<idl<<"#"<<idr<<lastl<<" "<<lastr<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}
