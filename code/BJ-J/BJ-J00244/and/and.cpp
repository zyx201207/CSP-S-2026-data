#define int long long
#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200001];
int b_to_d_1(int a){
    int ans[31]={},res;
    int i2=0;
    while(a){
        ans[i2++]=a%2;
        a/=2;
    }
    for(int i=0;i<i2;i++){
        res+=ans[i];
    }
    return res;
}
void dfs(vector<int> x,int ii){
    if(ii==m){
        int ma=x[0];
        for(int i=1;i<x.size();i++){
            ma&=x[i];
        }
        ans=max(ma,ans);
    }
    else{
        for(int i=ii;i<m;i++){
            x.push_back(a[i]);
            dfs(x,ii+1);
            x.pop_back();
        }
    }
    return;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,[](int x,int y){
        return x>y;
    });
    if(m==1){cout<<a[0];return 0;}
    else if(m==n){
        ans=a[0];
        for(int i=1;i<n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    else if(m==2){
        for(int i=0;i<n;i++){
            int ma=0;
            for(int j=i+1;j<n;j++){
                ma=max(ma,a[i]&a[j]);
            }
            ans=max(ma,ans);
        }
        cout<<ans;
        return 0;
    }
    else if(m==n-1){
        for(int i=0;i<n;i++){
            int ma=a[i];
            for(int j=0;j<n;j++){
                if(j!=i)ma&=a[j];
            }
        ans=max(ma,ans);
        }
        cout<<ans;
    }
    else{
        dfs({},0);
        cout<<ans;
    }
}
