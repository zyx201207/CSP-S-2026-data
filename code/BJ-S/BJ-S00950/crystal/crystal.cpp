#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],d,pre[500005],c;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        d=a[1]-a[i];
        pre[i]=pre[i-1]+d;
    }
    int l=1,r=1,ans=0;
    while(l<=r&&r<=n){
        if(pre[r]<=m){
            ans=max(ans,r-l+1);
            r++;
            m+=c;
        }else{
            l++;
            m+=(a[l-1]-a[l])*(r-l+1);
            c+=(a[l-1]-a[l]);
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
