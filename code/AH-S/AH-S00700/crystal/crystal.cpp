#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
int n,ans;
long long m,a[N],b[N];
bool check(int x){
    bool f=0;
    for(int i = 1;i<=n-x+1;i++){
        long long l = i,r=i+x-1;
        if((a[r]*x)-(b[r]-b[l-1])<=m)f=1;
    }
    return f;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    b[0]=0;
    for(int i = 1;i<=n;i++)b[i]=b[i-1]+a[i];
    int l=1,r=n;
    while(l!=r){
        int mid = (l+r)>>1;
        bool f = check(mid);
        if(f){
            ans=mid;
            l=mid+1;
        }
        else r=mid;
    }
    cout<<ans;
    return 0;
}
