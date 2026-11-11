#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,maxx;
int a[200005];
int check(int x){
    int cnt=0;
    while(x){
        if(x%2) cnt++;
        x/=2;
    }
    return cnt;
}
bool cmp(int a,int b){
    return a>b;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==1) cout<<maxx<<'\n';
    else if(m==n){
        ans=a[0];
        for(int i=1;i<n;i++){
            ans&=a[i];
        }
        cout<<ans<<'\n';
    }else if(n<=20){
        for(int i=0;i<=(1<<20);i++){
            int tmp=0;
            if(check(i)!=m) continue;
            for(int j=0;j<20;j++){
                if((i>>j)&1){
                    if(tmp==0) tmp=a[j];
                    else tmp&=a[j];
                }
            }
            ans=max(ans,tmp);
        }
        cout<<ans<<'\n';
    }else{
        sort(a,a+n,cmp);
        cout<<a[m]<<'\n';
    }
    return 0;
}
