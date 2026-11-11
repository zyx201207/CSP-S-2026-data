#include<iostream>
using namespace std;
#include<stdio.h>
constexpr int N=2e5+1;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        int maxx=-1;
        for(int i=1;i<=n;i++)maxx=max(maxx,a[i]);
        cout<<maxx;
        return 0;
    }else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }else if(m==2){
        int ans=-1;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
        }
        cout<<ans;
        return 0;
    }
    return 0;
}