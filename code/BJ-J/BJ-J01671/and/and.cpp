#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int n,m,an,maxa=INT_MIN,a[N],ans,sum;
int x[N];
bool b[N];
int ann(){
    sum=x[1];
    for(int i=2;i<=m;i++)
        sum=sum&x[i];
    return sum;
}
void dfs(int step){
    if(step==m+1){//buxuanl
        ans=max(ans,ann());
        return;
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            b[i]=1,x[step]=a[i];
            dfs(step+1);
            b[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        an=an&a[i],maxa=max(maxa,a[i]);
    }
    if(m==1){
        cout<<maxa;
        return 0;
    }
    if(m==n){
        cout<<an;
        return 0;
    }
    dfs(1);//yaoxuan dijige shu
    cout<<ans;
    return 0;
}