#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
ifstream fin("crystal.in");
ofstream fout("crystal.out");
#define cin fin
#define cout fout
long long a[500001],f[500001],n,m,ans=1;
long long calc(long long l,long long r)
{
    return f[r]-f[l]-(l-1)*(a[r]-a[l]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
    {
    	f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
    	//cerr<<f[i]<<' '; 
	}
    for(long long l=1,r=1;r<=n;r++)
    {
        long long cur=calc(l,r);
        while(cur>m)
        {
            l++;
            cur=calc(l,r);
        }
        ans=max(ans,r-l+1);
    }
    // cerr<<f[ans]<<' '<<m;
    // cerr<<' '<<f[ans+1];
    cout<<ans;
    return 0;
}
