#include <bits/stdc++.h>
using namespace std;
int a[100000005];
int n,m;
int cnt;
int maxx=-1;
void dfs(int step,int ii,int cnt){
    if(step==m){
        maxx=max(cnt,maxx);
    }else{
        for(int k=ii+1;k<n;k++){
            dfs(step+1,k,cnt&a[k]);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==m){
        cnt=a[0];
        for(int i=1;i<n;i++){
            cnt&=a[i];
        }
        cout<<cnt;
    }
    for(int i=0;i<n;i++){
        cnt=a[i];
        dfs(1,i,a[i]);
    }
    cout<<maxx;
    return 0;
}
