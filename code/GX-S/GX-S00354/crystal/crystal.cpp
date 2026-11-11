#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=500000+10;
long long n,m,ans=0;
long long s[N];
deque<long long>dque;
long long p=0;
int l=1,r=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&s[i]);
    sort(s+1,s+n+1);
    for(int i=1;i<=n;i++)
    {

        if(!dque.empty())
            p+=(s[i]-dque.back())*(long long)dque.size();
        dque.push_back(s[i]);
        //r++;
        while(p>m)
        {
            //cout<<s[i]-dque.front()<<endl;
            p-=s[i]-dque.front();
            dque.pop_front();
            //l++;
        }
        ans=max(ans,(long long)dque.size());
        //cout<<l<<" "<<r<<" "<<ans<<" "<<p<<endl;
    }
    cout<<ans;
    return 0;
}
