#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans=0;
int n,m;
int a[200005];
void dfs(int x,int i,int cnt)
{
    //di4 x ceng2  i:*a  ans cun2 jie3guo3
    if(x==m+1)
    {
        ans=max(ans,cnt);
        return ;
    }
    if(i>n+1) return;

    if(x==1){
        dfs(x+1,i+1,a[i]);
    }
    else dfs(x+1,i+1,cnt&a[i]);
    dfs(x,i+1,cnt);

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,1,100);
    cout<<ans;
    return 0;
}
