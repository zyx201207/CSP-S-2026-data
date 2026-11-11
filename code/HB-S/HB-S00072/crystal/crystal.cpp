#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[N],s1[N],s2[N];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    s1[1]=0,s2[n]=0;
    int ans1,ans2;
    for(int i=2;s1[i-1]<=m;i++){
        s1[i]=(a[i]-a[i-1])*(i-1)+s1[i-1];
        ans1=i-1;
    }
    for(int i=n-1;s2[i+1]<=m;i--){
        s2[i]=(a[n]-a[i])+s2[i+1];
        ans2=n-i;
    }
    cout<<max(ans1,ans2);
    return 0;
}
