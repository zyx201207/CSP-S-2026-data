#include<bits/stdc++.h>
using namespace std;
const int N=5e5+55;
long long a[N],s[N];
long long n,m;
bool check(int x,int y){
    long long num=(y-x+1)*(a[y])-(s[y]-s[x-1]);
    if(num<=m){
        return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    long long ans=1;
    for(int i=1;i<=n;i++){
        long long l=1,r=i;
        long long mid=(l+r)/2;
        while(l<r){
            if(check(mid,i)){
                ans=max(ans,i-mid+1);
                r=mid;
            }else{
                l=mid+1;
            }
            mid=(l+r)/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
