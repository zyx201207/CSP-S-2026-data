#include<bits/stdc++.h>
using namespace std;
int ans,n,m,a[200005];
int f(int a,int b){
    int a2[1048577]={},b2[1048577]={},sum=0;
    bool ans[1048577];
    while((a/2)!=0){
        int i=1;
        a2[i]=a%2;
        a/=2;
        b2[i]=b%2;
        b/=2;
        i++;
    }
    for(int i=0;;i++){
        ans[i]=(bool)a2[i]&&b2[i];
        sum+=ans[i]*(2^i);
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=m;j++){
            if(f(a[i],a[j])){
                ans=max(ans,f(a[i],a[j]));
            }
        }
    }
    cout<<ans;
    return 0;
}
