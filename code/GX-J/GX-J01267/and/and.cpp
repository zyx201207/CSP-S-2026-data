#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long p[200005];
long long n,m,mx=-1;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        sort(a+1,a+n+1,cmp);
        cout<<a[1];
        return 0;
    }else{
        for(int i=1;i<=n;i++){
            if(a[i+1]==a[i]){
                mx=max(a[i],mx);
            }
        }
        if(mx>0&&m==2){
            cout<<mx;
        }else{
            sort(a+1,a+n+1,cmp);
            long long ans=a[1];
            for(int i=1;i<=m;i++){
                ans-=a[i];
            }
        }

    }
    return 0;
}
