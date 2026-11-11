#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],b[N],ans[M];
bool checkA(int n){
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1])
            return false;
    }
    return true;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(checkA(n)){
        for(int i=1;i<=n;i++)
            ans[a[i]]=i;
        for(int i=1;i<=m;i++)
            cout<<ans[i]<<" ";
    }else{
        for(int i=1;i<=n;i++){
            int p=0;
            vector<int>lst(m+1),vis(m+1,0);
            for(int j=i;j<=n;j++){
                if(vis[a[j]]==0){
                    vis[a[j]]=1;
                    b[++p]=a[j];
                }else
                    p=lst[a[j]];
                lst[a[j]]=p;
            }
            for(int j=1;j<=p;j++)
                ans[b[j]]++;
        }
        for(int i=1;i<=m;i++)
            cout<<ans[i]<<" ";
    }
    return 0;
}
