#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,m,ans=0,cnt=0;
int a[N];
bool b[N];
void dfs(int x,int sum,int pre){
    if(x>=m){
        ans=max(ans,sum);
        return;
    }
    for(int i = pre+1;i<=n;i++){
        if(b[i]==0){
            b[i]=1;
            dfs(x+1,sum&a[i],i);
            b[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n>2000){
        cout<<a[1];
        return 0;
    }
    for(int i = 1;i<=n;i++){
        b[i]=1;
        dfs(1,a[i],i);
        b[i]=0;
    }
    printf("%d",ans);
}
