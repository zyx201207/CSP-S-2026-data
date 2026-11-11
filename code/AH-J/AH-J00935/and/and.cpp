#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=-1,xsum=1;
void dfs(int d,int cnt,long long sum){
    if(d>n){
        return ;
    }
    if(cnt>m){
        return ;
    }
    if(cnt==m){
        maxn=max(maxn,sum);
    }
    dfs(d+1,cnt,sum);
    dfs(d+1,cnt+1,(sum&a[d]));
}
int main(){
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xsum=(xsum&a[i]);
    }
    sort(a+1,a+n+1);
    if(m<=1){
        cout<<a[n];
    }else if(n==m){
        cout<<xsum;
    }else{
        dfs(1,0,2147483647);
        cout<<maxn;
    }
  fclose(stdin);
  fclose(stdout);
    return 0;
}
