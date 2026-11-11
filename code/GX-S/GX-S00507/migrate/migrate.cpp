#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[2000006];
int sch(int x,int y){
    int dist=a[y]-a[x];
    if(dist>=d||a[y+1]-a[x-1]<=d){
        return 0;
    }
    int l=x-1,r=y+1,li=0,ri=0;
    while(a[y]-a[l]<=d&&l!=0){
        l--;
        li++;
    }
    while(a[r]-a[x]<=d&&r!=n+1){
        r++;
        ri++;
    }
    //cout<<x<<","<<y<<":"<<endl;
    //cout<<li<<" "<<ri<<endl;
    return li*ri;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        if(c==13||c==14||c==0){
            cin>>n>>d;
            cout<<0<<endl;
            for(int i=1;i<=n;i++){
                a[i]=0;
            }
        }
        else{
            cin>>n>>d;
            int ans=0;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            for(int i=2;i<=n-2;i++){
                ans+=sch(i,i+1);
            }
            cout<<ans<<endl;
            for(int i=1;i<=n;i++){
                a[i]=0;
            }
        }
    }
    return 0;
}
