#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a[100005],maxn,x;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    maxn=0;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    maxn=0;
    for(int i=1;i<=n;i++){
        x=0;
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            if(j==1||j==2&&i==1){
                x=j;
            }else{
                x&=j;
            }
        }
        maxn=max(maxn,x);
    }
    cout<<maxn;
    return 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
