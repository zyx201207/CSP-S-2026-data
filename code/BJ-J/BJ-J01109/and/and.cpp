#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,q,a[200010],b[200010];
bool cmp(int l,int r){
    return l>r;
}
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    sort(b+1,b+1+n,cmp);
    ans=b[1];
    b[1]=0;
    for(int i=1;i<=m-1;i++){
        sort(b+1,b+1+n,cmp);
        for(int j=1;j<=n;j++){
            if(ans&b[j]!=0){
                ans=ans&b[j];
                b[j]=0;
                break;
            }
            b[j]=0;
        }
    }
    cout<<ans<<"\n";

    return 0;
}
