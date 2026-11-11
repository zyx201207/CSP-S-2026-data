#include<bits/stdc++.h>
using namespace std;
long long ai[200005];
long long n,a1,a2,a3,a4,a5,a6,a7,ans,all,h,t,z;//head,tail,zhongjian
char ci[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(a1=0;a1<n;a1++)
    {
        cin>>ai[a1]>>ci[a1];
        all+=ai[a1];
//        cout<<all<<" ";
    }
//    cout<<n;
    a1=0;
    for(a4=0;a4<n;a4++)
    {
        if(a1+ai[a4]>all/2)
        {
            a2=ai[a4];
            ai[a4]=all/2-a1;
            for(a3=n-1;a3>a4;a3--)
            {
                ai[a3+1]=ai[a3];
                ci[a3+1]=ci[a3];
            }
            ai[a4+1]=a2-ai[a4];
            ci[a4+1]=ci[a4];
            z=a4;
            t=n;
            break;
        }
        if(ai[a4]+a1==all/2)
        {
//            cout<<"a";
            z=a4;
            t=n-1;
            break;
        }
        a1+=ai[a4];
    }
/*
    cout<<z<<" "<<t<<'\n';
    for(a1=0;a1<=t;a1++)
    {
        cout<<ai[a1]<<" "<<ci[a1]<<'\n';
    }
*/
    for(h=0;h<=z;)
    {
        if(ai[h]>=ai[t])
        {
            if(ci[h]!=ci[t])
            {
                ans+=ai[t];
//                cout<<ans<<" ";
            }
            if(ai[h]==ai[t])
            {
                h++;
            }
            else
            {
                ai[h]-=ai[t];
            }
            t--;
        }
        else
        {
            if(ci[h]!=ci[t])
            {
                ans+=ai[h];
            }
            ai[t]-=ai[h];
            h++;
        }
    }
    cout<<ans;
    return 0;
}
