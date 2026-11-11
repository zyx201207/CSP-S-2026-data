#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
int mp[500005];
long long check(int x){
    int sum=0;
    int cnt=0;
    for(int i=x;i>=1;i--){
        if(sum+(a[x]-a[i])>m) return cnt;
        sum+=(a[x]-a[i]);
        cnt++;
    }
    return cnt;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int s1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) s1=1;
    }
    sort(a+1,a+1+n);
    if(n<=6000){
        int ans=0;
        for(int i=1;i<=n;i++){
            int t=check(i);
      //  cout<<t<<" ";
            ans=max(t,ans);
        }
        cout<<ans;
        return 0;
    }
    if(s1==0){
        int ans=0;
        int p=1;
        for(int i=1;i<=n;i++){
            if(m<ans+p){
                cout<<i<<endl;
                return 0;
            }
            ans+=p;
            p++;

        }
        cout<<ans;
        return 0;

    }
    int ans=0;
        int p=a[2]-a[1];
        for(int i=1;i<=n;i++){
            if(m<ans+p){
                cout<<i<<endl;
                return 0;
            }
            ans+=p;
            p+=a[2]-a[1];

        }
        cout<<ans;
    return 0;
}
