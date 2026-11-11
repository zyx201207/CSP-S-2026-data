#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[(int)1e6+5];
int ans=0;
int m;
int p[(int)1e6+5];
int c;
int z[(int)1e6+5];
int s(int l,int r){
    return z[r]-z[l]-l*(a[r]-a[l]);
}
bool check(int x){
    for (int i=0;i+x-1<n;i++){
        if (s(i,i+x-1)<=m) return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    cin>>a[0];
    z[0]=0;
    bool quan=1;
    for (int i=1;i<n;i++){cin>>a[i];}
    sort(a,a+n);
    p[0]=a[0];
    for (int i=1;i<n;i++){
        p[i]=a[i]-a[i-1];
        z[i]=z[i-1]+p[i]*i;
    }
    int l=1,r=n;
    while (l<=r){
        int mid=l+(r-l)/2;
        if (check(mid)){
            l=mid+1;
            ans=mid;
        }else r=mid-1;
    }
    /*
    bool bol=1;
    c=p[1];
    for (int i=2;i<n;i++) if (p[i]!=p[i-1]) bol=0;
    if (bol && n>500){
        //cout<<"bol"<<endl;
        int l=1,r=n;
        while (l<=r){
            int mid=l+(r-l)/2;
            if (check(mid)){
                l=mid+1;
                ans=mid;
            }else r=mid-1;
        }
    }
    for (int i=0;i<n;i++){
        int shu=m;
        int ji=1;
        for (int j=i-1;j>=0;j--){
            shu-=a[i]-a[j];
            if (shu<0) break;
            ji++;
        }
        ans=max(ans,ji);
    }
    */
    cout<<ans<<endl;
    return 0;
}
