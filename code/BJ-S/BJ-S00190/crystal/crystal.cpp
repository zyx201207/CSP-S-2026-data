#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define LL long long int
LL a[1000005];
LL sum[1000005];
bool cmp(LL a,LL b)
{
    return a>b;
}
int main()
{
    LL m,n;
    LL res=INT64_MIN;
    freopen("crystal.in","r",stdin);
    //freopen("crystal4.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        std::cin>>a[i];
    }
    std::sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        LL l=i,r=n;
        LL mid=(l+r)>>1;
        //std::cout<<i<<'\n';
        while(l<r)
        {
            mid=(l+r)>>1;
            //std::cout<<a[i]*(mid-i+1)-(sum[mid]-sum[i-1])<<"mid="<<mid<<'\n';
            if(a[i]*(mid-i+1)-(sum[mid]-sum[i-1])<=m)
                l=mid+1;
            else
                r=mid;
        }
        //std::cout<<"final"<<l<<'\n';
        if(a[i]*(l-i+1)-(sum[mid]-sum[i-1])<=m)
            res=std::max(l-i+1,res);
        else{
            for(long long int j=l;j>=1;j--)
                if(a[i]*(j-i+1)-(sum[mid]-sum[i-1])<=m){
                    res=std::max(j-i+1,res);
                    break;
                }
        }
        //std::cout<<"choss"<<i<<' '<<l<<' '<<l-i+1<<std::endl;
    }
    std::cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
