#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int cnt=0,n,m;
int dfs(int mx,int cnt,int i){
    if(cnt>=m){
        return mx;
    }
    if(i>=n){
        return -1;
    }
    int mn=mx&a[i];
    int mxx=-1;
    for(int j=i+1;j<=n;j++){
        mxx=max(mxx,dfs(mn,cnt+1,j));
    }
    if(mxx==-1){
        return -1;
    }
    return max(mxx,mx);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int mmxx=-1;
    for(int i=1;i<=n;i++){
        int temp=dfs(a[i],0,i);
        if(temp>mmxx){
            mmxx=temp;
        }
    }
    cout<<mmxx;
    return 0;
}


