#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,cnt,si;
queue<long long> q;

int main(void)
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        q.push(i);
        si++;
        long long ttt=a[i]-a[i-1];
        ttt*=(si-1);
        cnt+=ttt;
        while(cnt>m){
            cnt-=(a[i]-a[q.front()]);
            q.pop();
            si--;
        }
     //   cout<<i<<' '<<si<<' '<<cnt<<endl;
        ans=max(ans,si);
    }
    cout<<ans<<endl;


    return 0;
}
