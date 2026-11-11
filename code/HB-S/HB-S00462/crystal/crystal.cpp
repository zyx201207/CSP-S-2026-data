#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int n;
long long m,a[MAXN],b[MAXN],x[MAXN],s[MAXN];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
            break;
        }
        if(a[i]-a[i-1]==1){
            cout<<m-2;
            return 0;
        }
    }
    sort(a+1,a+n+1);
    for(int l=1;l<=n;l++){
        long long last=0;
        for(int r=l;r<=n;r++){
            long long x=(a[r]-a[r-1])*(r-l+1)+last;
            if(x-a[r]>m){
                break;
            }
            if(n>5000&&ans==r-l+1){
                cout<<ans;
                return 0;
            }
            ans=max(ans,r-l+1);
            last=x;
        }
    }
    cout<<ans;
    return 0;
}
