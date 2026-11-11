#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=1,i2=2;
bool bfs(long long x,long long b){
    if(b==m)return 1;
    if(upper_bound(a,a+n,x)-lower_bound(a,a+n,x)>=i2){
            i2++;
        return bfs(x,b+1);
    }
    if(a[lower_bound(a,a+n,x*2+1)-a]==x*2+1){
        return bfs(x*2+1,b+1);
    }else return 0;
}
int main(){
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
    cin>>n>>m;
    bool flag=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=0)flag=0;
    }
    if(flag){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(bfs(a[i],1))ans=max(ans,a[i]);
    }cout<<ans;
    return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
