#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
long long ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==m){
        ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
    }else if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>ans) ans=a[i];
        }
    }else if(m==2){
        long long x=0;
        for(int i=1;i<=n;i++){
            x=a[i];
            for(int j=i;j<=n;j++){
                x&=a[j];
            }
            if(x>ans) ans=x;
        }
    }
    cout<<ans;
    return 0;
}
