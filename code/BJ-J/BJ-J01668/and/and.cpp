#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];long long ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    for(int i=30;i>=0;i--){
        if(i==0)ans+=1;
        ans+=2<<(i-1);
        long long cnt=0;
        for(int i=1;i<=n;i++){
            long long c=ans&a[i];
            if(c==ans){
            cnt++;
            }
        }
        if(cnt<m){
            ans-=2<<(i-1);
            if(i==0)ans-=1;
        }
    }
    cout<<ans;
    return 0;
}