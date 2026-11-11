#include<bits/stdc++.h>
using namespace std;
int flat=0;
long long c,t;
int  n,m,d,zd,ans,q;
int  x[100000];
long long dp[10005][10005];
long long cnt[10005][10005];
int f(int u){
    int l=1,r=n;
    int mid=(l+r)/2;
    while(l<=r){
        mid=(l+r)/2;
        if(x[mid]==u)return mid-1;
        else if(x[mid]<u)l=mid+1;
        else r=mid-1;
    }
    return mid;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>n>>d>>q;
        ans=0;
        for(int i=1;i<=m;i++){
            cin>>x[i];
            if(x[i]-1!=x[i-1])flat=1;}


        for(int i=1;i<=n;i++){
            int u=x[i]+2*d;
            int r=f(u);

            //if(i==1)cout<<"I";
            if(r-i==3&&x[r]-x[r-1]<=d&&x[r-2]-x[i]<=d&&!(x[r]-x[i]<=d)){ans++;}
            //cout<<x[i]<<" "<<u<<" "<<r<<" "<<ans<<endl;

        }
        cout<<ans<<endl;


    return 0;
}
