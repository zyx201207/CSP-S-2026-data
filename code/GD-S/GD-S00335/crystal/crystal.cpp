#include<bits/stdc++.h>
#define int long long
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int N=5e5+10;
int n,m,ans,a[N],pre[N];
bool check(int l,int r){
    int len=r-l+1;
    int sum1=len*a[r],sum2=pre[r]-pre[l-1];
    return sum1-sum2<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    For(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    For(i,1,n) pre[i]=pre[i-1]+a[i];
    For(i,1,n){
        int l=1,r=i,res=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,i)) r=mid-1,res=mid;
            else l=mid+1; 
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans;
    return 0;
}

//9 min