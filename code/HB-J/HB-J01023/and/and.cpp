#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long  n,m,a[N],ans;
int k;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n==m){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i==1) k=a[i];
            else k=(k&a[i]);
        }
        cout<<k;
        return 0;
    }
    /*if(m==2){
        for(int i=1;i<=n;i++) cin>>a[i];
        long long x,y;
        for(int i=1;i<=n;i++) x=max(x,a[i]);
        for(int i=1;i<=n;i++){
            if(a[i]!=x) y=max(y,a[i]);
        }
        cout<<x<<y;
        cout<<(x&y);
        return 0;
    }*/
    if(m==1){
        long long max_a;
        for(int i=1;i<=n;i++) max_a=max(max_a,a[i]);
        cout<<max_a;
        return 0;
    }
    sort(a+1,a+1+n);
    ans=a[n];
    for(int i=n-1;i>=m;i--) ans=(ans&a[i]);
    cout<<ans;
    return 0;
}
