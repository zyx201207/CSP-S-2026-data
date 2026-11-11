#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m,ans;
int a[N];
bool flag1=true,flag2=true;
void solve1(){
    int M=m;
    for(int i=1;i<=n;i++){
        if(M>=i)M-=i;
        else {
            ans=i;
            break;
        }
    }
    cout<<ans;
}
void solve2(){
    int mi=a[2]-a[1],M=m,sum=0;
    int x=M/mi;
    for(int i=1;i>=1;i++){
        sum+=i;
        if(sum>x){
            ans=i;
            break;
        }
    }
    cout<<ans;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)flag1=false;
        if(i>2)
            if(a[i]-a[i-1]!=a[i-1]-a[i-2])
                flag2=false;
    }
    if(flag1){
        solve1();
        return 0;
    }
    if(flag2){
        solve2();
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int cnt=0,M=m;
        for(int j=i;j>=1;j--){
            if(M>=a[i]-a[j]){
                M=M-a[i]+a[j];
                cnt++;
            }
            else break;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
