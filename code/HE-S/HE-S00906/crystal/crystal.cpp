#include <bits/stdc++.h>
using namespace std;
int m,a[5005],ans=0;int n;
int b(long long tongyi){
    int shu=0,q[5005]={},sum=m,cnt=0;
    for(int i=1;a[i]<=tongyi;i++){
        q[shu]=tongyi-a[i];
        shu++;
    }
    for(int i=shu-1;i>=0;i--){
        if(q[i]>sum){
            break;
        }
        else{
            sum-=q[i];
            cnt++;
        }
    }
    return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n,mid,u;
    while(l<=r){
        mid=(l+r)/2;
        u=b(a[mid]);
        if(u<ans){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
        ans=max(ans,u);
    }
    cout<<ans;

    return 0;
    fclose(stdin);
    fclose(stdout);

}
