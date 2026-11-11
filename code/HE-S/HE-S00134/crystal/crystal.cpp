#include<bits/stdc++.h>
using namespace std;
int a[500005];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ma=0;
    for(int i=1;i<=n;i++){
        int ans=1,w=m;
        for(int j=i-1;j>=1;j--){
            if(w<1){break;}
            else if(w<a[i]-a[j])continue;
            else{
                w-=a[i]-a[j];
                ans++;
            }
        }
        ma=max(ma,ans);
    }
    cout<<ma;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
