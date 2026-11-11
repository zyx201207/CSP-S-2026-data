#include <bits/stdc++.h>
using namespace std;
long long rd(){
    long long sum=0;int min=1;char c='a';
    while(c<'0'||c>'9')
    {
        if(c=='-') min=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9')
    {
        sum=(sum<<3)+(sum<<1)+c-'0';
        c=getchar_unlocked();
    }
    if(min==-1) return 0-sum;
    return sum;
}
int const MAX=600002;
long long c[MAX];
long long find(long long n,long long m)
{
    long long ans=-1e5;
    if(n ==1) return 1;
    for(long long i = 2;i <= n;i++)
    {
        long long cnt=1;long long a=m;
        for(long long j=i-1;j>=1&&a>=0;j--)
        {
                a-=c[i]-c[j];
                cnt++;
        }
        ans=max(ans,cnt);
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::ios::sync_with_stdio(1);
    cin.tie(0);cout.tie(0);
    long long n,m;long long tmp;
    cin>>n>>m;
    getchar();
    for(long long i=1;i<=n;i++)
        c[i]=rd();
    sort(c+1,c+n+1);
    long long ans=find(n,m);
    cout<<ans<<endl;
    return 0;
}