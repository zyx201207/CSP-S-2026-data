#include<bits/stdc++.h>
using namespace std;
struct sl{
    int num;
    char a;
}c[200010];
int n,tr,tl,l,r;
long long ans[200010],sum=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i].num>>c[i].a;
        ans[i]+=c[i].num+ans[i-1];
    }
    long long lenn=ans[n],mid=0;
    if(lenn%2==0)lenn/=2;
    else {
        lenn/=2;lenn++;
    }
    for(int i=1;i<=n;i++)
    {
        if(lenn<=ans[i]){
            mid=i;
            if(ans[n]%2==1)
            {
                l=lenn-ans[i-1]-1;
                r=ans[i]-lenn;
                tl=i;
                tr=i;
                if(l==0)
                {
                    l=c[--tl].num;
                }
                if(r==0)
                {
                    r=c[++tr].num;
                }
            }
            else
            {
                l=lenn-ans[i-1];
                r=ans[i]-lenn;
                tl=i;
                tr=i;
                if(l==0)
                {
                    l=c[--tl].num;
                }
                if(r==0)
                {
                    r=c[++tr].num;
                }
            }
            break;
        }
    }
    while(tl>=0&&tr<=n)
    {
        if(c[tl].a!=c[tr].a)
        {
            sum+=min(r,l);
            int temp=min(r,l);
            l-=temp;
            r-=temp;
        }
        if(c[tl].a==c[tr].a)
        {
            int temp=min(r,l);
            r-=temp;
            l-=temp;
        }
        if(l==0)
        {
            l=c[--tl].num;
        }
        if(r==0)
        {
            r=c[++tr].num;
        }
    }
    cout<<sum<<endl;
    return 0;
}
