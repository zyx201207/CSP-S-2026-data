#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,num=0,ans=1;
int a[N];
int cha[N];
int d[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        cha[i-1]=a[i]-a[i-1];
        d[i-1]=d[i-2]+cha[i-1];
    }
    int l=0,r=0;
    while(l<=r&&r<n){
        //cout<<l<<" "<<r<<" "<<num<<"\n";
        if(num<=m||(num>m&&l==r)){
            ans=max(ans,r-l+1);
            num+=cha[r+1]*(r-l+1);
            r++;
        }
        else{
            num-=d[r]-d[l-1];
            l++;
        }
    }
    cout<<ans;
    return 0;
}
