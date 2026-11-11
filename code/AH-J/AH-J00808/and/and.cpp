#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int ans=-1;
bool flag[200005];
int t[200005];
void dfs(int m,int step){
    if(step>m){
        int and_=t[1];
        for(int i=2;i<=m;i++){
            and_&=t[i];
        }
        ans=max(ans,and_);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!flag[i]){
            flag[i]=1;
            t[step]=a[i];
            dfs(m,step+1);
            flag[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans<<endl;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int _and=a[i];
                _and&=a[j];
                ans=max(_and,ans);
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    dfs(m,1);
    cout<<ans<<endl;
    return 0;
}