#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int a[2000010],l[2000010],r[2000010],b[2000010],t[2000010];
void solve()
{
    int i,ans=0;cin>>n>>d;
    for(i=1;i<=n;i++)cin>>a[i],b[i]=t[i]=0;
    for(i=1;i<=n;i++){
        r[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
        l[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
        //cout<<l[i]<<' '<<r[i]<<'\n';
    }for(i=n;i;i--){
        if(r[i]==i)continue;
        if(l[r[r[i]]]==r[i])b[i]+=b[r[i]];
        if(l[r[r[i]]]==r[i]-1)b[i]+=t[r[r[i]]];
        //yuanshen
		b[i]+=(lower_bound(l+r[i]+1,l+r[r[i]]+1,r[i])-lower_bound(l+r[i]+1,l+r[r[i]]+1,r[i]-1));
        // for(int j=r[i]+1;j<=r[r[i]];j++)
            // if(l[j]==r[i]-1)b[i]++;

        if(l[r[i]]==i)t[i]+=t[r[i]];
        t[i]+=(lower_bound(l+i+1,l+r[i]+1,i+1)-lower_bound(l+i+1,l+r[i]+1,i));
         //for(int j=i+1;j<=r[i];j++)
            // if(l[j]==i)t[i]++;
        ans+=b[i];
        //cout<<b[i]<<' '<<t[i]<<'\n';
    }cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int __,_;cin>>__>>_;
    while(_--)solve();
}
/*
0 1
10 21
0 7 14 21 28 35 42 49 56 63
*/
