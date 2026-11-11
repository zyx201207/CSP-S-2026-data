//long long    ###
//int
#include<bits/stdc++.h>
using namespace std;
int c;
//-------------
int n,d,a[2000009];
int ls[2000009],ss[2000009];
void dfs(int u,int l){
    if(l==ls[u]){
        ss[u]++;
    }
    if(l<ls[u]){
        ls[u]=l;
        ss[u]=1;
    }
    for(int i=u+1;a[i]-a[u]<=d&&i<=n;i++){
        dfs(i,l+1);
    }
    return;
}
void init(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n-2;i++){
        for(int j=i;j<=n;j++){
            ls[j]=0;
            ss[j]=0;
        }
        dfs(i,0);
        for(int j=i;j<=n;j++){
            if(ss[j]==2){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
//------------
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        init();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
