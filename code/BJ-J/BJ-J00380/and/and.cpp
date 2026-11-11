#include<bits/stdc++.h>
using namespace std;
int a[200005][35],b[200005];
int vis[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,Max=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        b[i]=tmp;
        int j=0;
        while(tmp>0){
            a[i][++j]=tmp%2;
            tmp/=2;
        }
        Max=max(Max,j);
    }
    for(int i=Max;i>=1;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]==1&&vis[j]==0){
                cnt++;
            }
        }
        if(cnt>=m){
            for(int j=1;j<=n;j++){
                if(a[j][i]==0&&vis[j]==0){
                    vis[j]=1;
                }
            }
        }
        /*
        for(int j=1;j<=n;j++){
            cout<<vis[j]<<" ";
        }
        cout<<'\n';
        */
    }
    int cnt=0,ans=-1;
/*
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
        for(int j=1;j<=Max;j++){
            cout<<a[i][j];
        }
        cout<<'\n';
    }
    */
    for(int i=1;i<=n;i++){

        if(vis[i]==0){
            if(ans==-1){
                ans=b[i];
            }
            else{
                ans&=b[i];
            }
            cnt++;
        }
        if(cnt==m){
            cout<<ans;
            return 0;
        }
    }


    return 0;
}
