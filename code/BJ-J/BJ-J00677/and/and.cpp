#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
int a[N];
int maxx=0;
bool st[N];
int n,m,ans=0;
void dfs(int x,int s,int sum){
    if(s==m) maxx=max(maxx,sum);
    for(int i=x;i<=n;i++){
        if(!st[i]){
            st[i]=1;
            dfs(i,s+1,sum&a[i]);
            st[i]=0;
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
    for(int i=1;i<=n;i++){
        st[i]=1;
        dfs(i,1,a[i]);
        st[i]=0;
    }
    cout<<maxx<<endl;
    return 0;
}
