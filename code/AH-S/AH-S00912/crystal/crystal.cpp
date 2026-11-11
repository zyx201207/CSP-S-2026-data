#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;
long long a[N],sum[N],m;
int n;
bool check(int x,int y){
    long long ss=sum[y]-sum[x-1];
    long long g=a[y]*(y-x+1);
    return g-ss<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int w=1;
    for(int i=1;i<=n;i++){
        while(!check(w,i)) w++;
        ans=max(ans,i-w+1);
    }
    cout<<ans<<endl;
    return 0;
}