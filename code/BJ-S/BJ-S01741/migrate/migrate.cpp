#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(1){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            if(a[n]>=2*d-1+a[1]-1){
                int d1=d;
                d=a[2]-a[1]+1;
                int l=1,r=n,res=-1;
                int x=2*d-1+a[1]-1;
                if(x-d1<a[1]){
                    cout<<0<<"\n";
                    continue;
                }
                while(l<=r){
                    int mid=(l+r)/2;
                    if(a[mid]==x){
                        res=mid;
                        break;
                    }else if(a[mid]<x){
                        l=mid+1;
                    }else{
                        r=mid-1;
                    }
                }
                cout<<n-res<<"\n";
            }else cout<<0<<"\n";
        }
    }//else if()

    return 0;
}
