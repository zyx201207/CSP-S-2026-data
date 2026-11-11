#include<bits/stdc++.h>
using namespace std;
#define int long long
struct jk{
    int a;
    char b;
} d[200005];
int a,l=1,r,sum=0;
void s(jk &x,jk &y)
{
    jk t={x.a,x.b};
    x=y;
    y=t;
    return;
}
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    r=a;
    for(int i=1;i<=a;i++) cin>>d[i].a>>d[i].b;
    while(l<r)
    {
        //cout<<l<<" "<<r<<" "<<sum<<"\n";
        if(l+1==r and d[l].b==d[r].b) break;
        if(d[l].a>d[r].a)
        {
            if(d[l].b==d[r].b)
            {
                sum+=d[l].a-d[r].a;
                int cs=d[l].a-d[r].a;
                char t=d[r].b;
                r--;
                l++;
                while(l<r and cs>0)
                {
                    if(d[r].a<=cs)
                    {
                        if(d[r].b==t) sum-=d[r].a;
                        cs-=d[r].a;
                        r--;
                    }
                    else
                    {
                        if(d[r].b==t) sum-=cs;
                        d[r].a-=cs;
                        cs=0;
                    }
                }
            }
            else
            {
                sum+=d[r].a;
                d[l].a-=d[r].a;
                if(d[l].a==0) l++;
                r--;
            }
        }
        else
        {
            if(d[l].b==d[r].b)
            {
                sum+=d[r].a-d[l].a;
                int cs=d[r].a-d[l].a;
                char t=d[l].b;
                r--;
                l++;
                while(l<r and cs>0)
                {
                    if(d[l].a<=cs)
                    {
                        if(d[l].b==t) sum-=d[l].a;
                        cs-=d[l].a;
                        l++;
                    }
                    else
                    {
                        if(d[l].b==t) sum-=cs;
                        d[l].a-=cs;
                        cs=0;
                    }
                }
            }
            else
            {
                //if(l==3 and r==4)
                //{

                    //cout<<sum<<" "<<d[l].a<<"\n";
                //}
                sum+=d[l].a;
                d[r].a-=d[l].a;
                if(d[r].a==0) r--;
                l++;
            }
        }
    }
    cout<<sum;
    return 0;
}
