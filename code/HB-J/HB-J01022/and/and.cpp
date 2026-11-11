#include<bits/stdc++.h>
using namespace std;
const int mx=2010;
int a[mx];
int n,m,maxn;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    else if(m==2){
        maxn=-1;
        for(int i=1;i<=n;i++){
            int x=a[i];
            for(int j=i+1;j<=n;j++){
                int t=x&a[j];
                if(t>maxn) maxn=t;
            }
        }
        cout<<maxn;
    }
    return 0;
}
//I hope I can get better grade T^T
//I will be better!
//I will join in the CSP-S test in the afternoon
//But I can't write anything...
//Even though,I like programming as past as like playing
