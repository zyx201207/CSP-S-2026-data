#include <bits/stdc++.h>
using namespace std;

int n;
long long a[500005];
long long m,ans,pjs;

int main()
{
    //delete "//" or u r gay
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans+=a[i];
    }


    pjs=ans/n;
    int z7=0,x=0,sum=0;
    while(m>0&&z7==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(abs(pjs-a[i])==x&&m>=x){
                m-=x;
                a[i]=pjs;
                sum++;
            }
            else if(m<x)
                break;
        }
    sort(a+1,a+1+n);
    if(a[1]==a[n])
    {
        sum=n;
        break;
    }
        x++;
    }
    cout<<sum;
    return 0;
}
