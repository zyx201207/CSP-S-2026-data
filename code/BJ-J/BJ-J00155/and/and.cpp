#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
    if(n>=100000 || m==1){
        int nmax=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(nmax<a[i]) nmax=a[i];
        }
        cout<<nmax;
        return 0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==2){
        int nmax=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int tmp=a[i]&a[j];
                if(tmp>nmax) nmax=tmp;
            }
        }
        cout<<nmax;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=1;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        int ans=a[n],nmax=0;
        for(int i=1;i<=n;i++){
            if(i==n) ans=a[1];
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                ans&=a[j];
            }
            if(ans>nmax) nmax=ans;
        }
        cout<<nmax;
        return 0;
    }
    return 0;
}
