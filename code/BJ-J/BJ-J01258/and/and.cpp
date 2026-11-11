#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans[200005],vis[200005];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1]<<endl;
        return 0;
    }
    if(m==2){
        long long mx=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,a[i]&a[j]);
            }
        }
        cout<<mx;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        int mx=-1;
        for(int i=1;i<=n;i++){
            int ans=(i!=1?a[1]:a[2]);
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                else ans=ans&a[j];
            }
            mx=max(mx,ans);
        }
        cout<<mx;
        return 0;
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(a[i]!=i-1){
            flag=false;
            break;
        }
    }
    if(flag){
        int x;
        for(int i=1;i<=30;i++){
            if(pow(2,i)<=m&&pow(2,i+1)>m){
                x=i;
                break;
            }
        }
        long long ans=a[(int)pow(2,x+1)-1];
        for(int i=pow(2,x+1)-1;i>=pow(2,x+1)-1-m;i--){
            ans=ans&i;
        }
        cout<<ans<<endl;
        return 0;
    }
    bool flag2;
    for(int i=1;i<=n;i++){
        flag2=false;
        for(int j=0;j<=30;j++){
            if(a[i]-pow(2,j)<1&&a[i]-pow(2,j)>-1){
                flag2=true;
                break;
            }
        }
        if(!flag2){
            break;
        }
    }
    if(flag2){
        int ans=a[1];
        for(int i=1;i<=m;i++){
            ans=ans&a[i];
        }
        cout<<ans<<endl;
        return 0;
    }
    int x=a[1];
    for(int i=1;i<=m;i++){
        x=x&a[i];
    }
    cout<<x;
    return 0;
}
