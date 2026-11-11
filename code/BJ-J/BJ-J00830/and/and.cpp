#include<bits/stdc++.h>
using namespace std;
int n,m,a[114514],ans;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==2&&n<=2000){
        ans=-114514;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i]&a[j]>ans){
                    ans=a[i]&a[j];
                }
            }
        }
    }else{
        ans=2147483647;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=m;i++){
            ans=ans&a[i];
        }
    }
    cout<<ans;
    return 0;
}
