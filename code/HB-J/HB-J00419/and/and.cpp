#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
long long a[200010];
int b[200010];
void gg(int x,long long s){
    if(s<=ans){
        return;
    }
    if(x==m+1){
        ans=s;
        return;
    }
    for(int j=1;j<=n;j++){
        if(b[j]==0){
            b[j]=1;
            gg(x+1,s&a[j]);
            b[j]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=1;
        gg(2,a[i]);
        b[i]=0;
    }
    cout<<ans;
    return 0;
}
