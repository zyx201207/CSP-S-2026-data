#include<bits/stdc++.h>
using namespace std;
struct duan_
{
    long long cnt;
    char zi;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n=0,chang=0,mid=0;
    cin>>n;
    vector<duan_> duan(n+2);
    for(long long i=1;i<=n;i++)
    {
        cin>>duan[i].cnt;
        chang=chang+duan[i].cnt;
        char zhong_jie;
        cin>>zhong_jie;
        duan[i].zi=zhong_jie;
    }
    mid=(chang+chang%2ll)/2ll-1ll;
    long long ans=0;
    long long l=0,r=0,l_b=1,r_b=n,lnow=duan[1].cnt,rnow=duan[n].cnt;
    while(l_b<=r_b)
    {
        //cout<<ans<<" "<<l_b<<" "<<r_b<<" "<<lnow<<" "<<rnow<<endl;
        if(lnow>rnow)
        {
            if(duan[l_b].zi!=duan[r_b].zi)
            {
                ans=ans+rnow;
            }
            lnow=lnow-rnow;
            r_b--;
            if(r==mid)
            {
                break;
            }
            else if(r<mid&&r+duan[r_b].cnt>mid)
            {
                rnow=mid-r;
                r=mid;
            }
            else
            {
                rnow=duan[r_b].cnt;
                r=r+duan[r_b].cnt;
            }
        }
        else if(lnow==rnow)
        {
            if(duan[l_b].zi!=duan[r_b].zi)
            {
                ans=ans+lnow;
            }
            r_b--;
            l_b++;
            if(r==mid)
            {
                break;
            }
            else if(r<mid&&r+duan[r_b].cnt>mid)
            {
                rnow=mid-r;
                r=mid;
            }
            else
            {
                rnow=duan[r_b].cnt;
                r=r+duan[r_b].cnt;
            }
            if(l==mid)
            {
                break;
            }
            else if(l<mid&&l+duan[l_b].cnt>mid)
            {
                lnow=mid-r;
                l=mid;
            }
            else
            {
                lnow=duan[l_b].cnt;
                l=l+duan[l_b].cnt;
            }
        }
        else if(lnow<rnow)
        {
            if(duan[l_b].zi!=duan[r_b].zi)
            {
                ans=ans+lnow;
            }
            rnow=rnow-lnow;
            l_b++;
            if(l==mid)
            {
                break;
            }
            else if(l<mid&&l+duan[l_b].cnt>mid)
            {
                lnow=mid-r;
                l=mid;
            }
            else
            {
                lnow=duan[l_b].cnt;
                l=l+duan[l_b].cnt;
            }
        }
    }
    cout<<ans;
    return 0;
}
