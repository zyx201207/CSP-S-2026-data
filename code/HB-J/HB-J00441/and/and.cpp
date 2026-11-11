#include<bits/stdc++.h>
#define int long long
#define pi 3.1415926
using namespace std;
int n,m,ans=INT_MAX;
int a[200005];
int k[200005];
bool flagA=1,flagB=1,flagC=1;
void dfs(int x){
    if(x==0){
        int num=INT_MAX;
        for(int i=1;i<=m;i++){
            num=num&a[k[i]];
        }
        ans=max(num,ans);
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-x;j++){
            if(k[j]==i){
                return;
            }
        }
        k[m-x+1]=i;
        dfs(x-1);
        k[m-x+1]=0;
    }
    return;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int k=a[i]+1;
        while(k){
            if(k%2){
                break;
            }
            k/=2;
        }
        if(k==0){
            flagA=0;
        }
        if(a[i]!=i-1){
            flagB=0;
        }
        if(a[i]>3){
            flagC=0;
        }
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[m];
    }
    else if(m==n||m==n-1){
        int num=INT_MAX;
        for(int i=1;i<=n;i++){
            num=num&a[i];
        }
        cout<<num;
        return 0;
    }
    else if(flagA){
        cout<<a[n-m+1];
        return 0;
    }
    else if(flagB){
        for(int i=n;i>=n-m+1;i--){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    else if(flagC){
        if(a[1]==0){
            cout<<0;
            return 0;
        }
        else if(a[1]==1){
            for(int i=1;i<=n;i++){
                if(a[i]==2){
                    cout<<0;
                    return 0;
                }
            }
            cout<<1;
            return 0;
        }
        else if(a[1]==2){
            cout<<2;
            return 0;
        }
        else{
            cout<<3;
            return 0;
        }
        return 0;
    }
    dfs(m);
    cout<<ans;
    return 0;
}
