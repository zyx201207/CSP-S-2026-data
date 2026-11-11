#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        int ans=a[1];
    for(int i=1;i<=n;i++){
         ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        int maxn=0;
        for(int i=1;i<=n;i++){
            if(a[i]>maxn) maxn=a[i];
        }
        cout<<maxn;
        return 0;
    }
    if(m==2){
            int maxn=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(a[i]&a[j]>maxn) maxn=a[i]&a[j];
            }
        }
    cout<<maxn;
    return 0;
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[m];
}
