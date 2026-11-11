#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
int a[N];
int ans=-1e9;
int Max=-1e9;
void dfs(int x,int sum,int Ans){
    for(int i=x+1;i<=n;i++){
        dfs(i,sum+1,(Ans&a[i]));
    }
    if(sum==m){
        ans=max(ans,Ans);
        return;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        Max=max(Max,a[i]);
    }
    if(m==1){
        cout<<Max;
        return 0;
    }else if(m==n){
        int sans=a[1];
        for(int i=2;i<=n;i++){
            sans&=a[i];
        }
        cout<<sans;
        return 0;
    }else if(m==2){
        int sans=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,(a[i]&a[j]));
            }
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        dfs(i,1,a[i]);
    }
    cout<<ans;
    return 0;
}
