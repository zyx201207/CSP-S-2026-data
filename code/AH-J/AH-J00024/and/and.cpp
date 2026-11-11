#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(m==2){
        int ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                ans=max(ans,(a[i]&a[j]));
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        cout<<0;
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    int ans=a[1];
    for(int i=2;i<=m;i++){
        ans=(ans&a[i]);
    }
    cout<<ans;
    return 0;
}
