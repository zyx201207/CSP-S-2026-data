#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],sum;
char b[200005];
long long s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%s",&a[i],&b[i]);
        sum+=a[i];
    }
    int head=1,werse=sum;
    int wh=1,ww=n;
    while(werse-head>=1)
    {
        if(a[wh]<a[ww])
        {
            head+=a[wh];
            werse-=a[wh];
            if(b[wh]!=b[ww])
                s+=a[wh];
            a[ww]-=a[wh];
            wh++;
        }
        if(a[wh]>a[ww])
        {
            head+=a[ww];
            werse-=a[ww];
            if(b[wh]!=b[ww])
                s+=a[ww];
            a[wh]-=a[ww];
            ww--;
        }
        if(a[wh]==a[ww])
        {
            head+=a[ww];
            werse-=a[ww];
            if(b[wh]!=b[ww])
                s+=a[ww];
            ww--;
            wh++;
        }
    }
    cout<<s;
    return 0;
}
