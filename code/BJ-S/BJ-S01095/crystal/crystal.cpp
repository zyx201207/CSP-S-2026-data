#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+9;

int n,a[N],m;

int l,r,val,tot,ans;

#define update() if(tot<=m){ans=max(ans,r-l+1);}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin>>n>>m;
    for(int i = 1; i<=n;i++) { cin>>a[i];
    }

    sort(a+1,a+1+n);

    l=1;
    r=1;
    val=a[1];
    tot=0;//op
    ans=1;
    for(;l<n;){
        while(r<n){
            update();

            int cnt=r-l+1;
            ++r;
            val=a[r];
            tot+=(cnt)*(a[r]-a[r-1]);

            update();
        }
        ++l;
        tot-=a[r]-a[l-1];
        update();
    }
    cout<<ans;

    return 0;
}
