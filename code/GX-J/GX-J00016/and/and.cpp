#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[200005],maxx=0;
void dfs(int k,int j=0){
    if(j==n+5)return;
    if(k==m){
        int sum;
        for(int i=1;i<=m;i++){
            if(i==1)sum=a[vis[i]];
            else{
                sum=sum&a[vis[i]];
                //cout<<vis[i]<<" ";
            }
        }
        //cout<<" "<<sum<<endl;
        maxx=max(maxx,sum);
        return;
    }
    j++;
    k++;
    vis[k]=j;
    dfs(k,j);
    vis[k]=0;
    dfs(k-1,j);
    return;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>25){
        sort(a+1,a+1+n);
        int sum=a[n];
        while(n>m)sum=sum&a[n--];
        cout<<sum;
        return 0;
    }
    dfs(0);
    cout<<maxx;
    return 0;
}
