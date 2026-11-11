#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> v;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    v.push_back(-114514);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    long long z=(n%2==1)?n/2+1:n/2;
    sort(v.begin()+1,v.end());
    if(v[z]-v[z-1]>m){cout<<1;return 0;}
    int cnt=0;
    for(int i=1;i<=n;i++){if(v[i]==v[z])cnt++;}
    //cout<<cnt;
    for(int i=1;i<=n/2;i++)
    {
        m-=v[z]-v[z-i];
        if(m<0)
        {
            cout<<i-1+cnt;
            return 0;
        }
    }
    if(m==0)cout<<n/2+cnt;
    else{
        if(m<v[z+1]-v[z])cout<<n/2+cnt;
        else
        {
            int cc=0;
            for(int i=1;i<=n/2;i++)
            {
                if(v[z+i]==v[z])
                continue;
                m-=(v[z+i]-v[z])*(n/2+i);
                if(m<0)
                {
                    cout<<cc+1+n/2+cnt;
                    return 0;
                }
                else cc++;
            }
        }

    }
    return 0;
}
