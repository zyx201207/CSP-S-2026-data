#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> v;
signed main()
{
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,t;
    cin>>n>>t;
    for(int i=0,x;i<n;++i)
    {
        cin>>x;
        v.push_back(x);
    }
    if(t==1)
    {
        int maxn=0;
        for(int i=0;i<n;++i)
        {
            maxn=max(v[i],maxn);
        }
        cout<<maxn;
    }
    else if(t==2)
    {
        int maxn=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            maxn=max(v[i]&v[j],maxn);
        }
        cout<<maxn;
    }
    else
    {
        bool flag=0;
        for(int i=0;i<n;++i)
        {
            if(v[i]>4)
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            sort(v.begin(),v.end());
            cout<<v[n-t];
        }
        else
        {
            int fl=0;
            for(int i=0;i<n;++i)
            {
                if(v[i]!=i)
                {

                    fl=1;
                    break;
                }
            }
            if(!fl)
            {
                cout<<23323232;
                int cnt=0,crt=0;
                while(n>0)
                {
                    n/=2;
                    cnt++;
                }
                while(n-pow(2,cnt)<t)
                {
                    cnt--;
                }
                cout<<pow(2,cnt);
            }
            else
            {
                    sort(v.begin(),v.end());
                    cout<<v[n-t];
            }


        }

    }
    return 0;
}
