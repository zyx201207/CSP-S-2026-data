/*
4 2
2 3 15 12 12

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int m;
int a[200005];
int b[200005];
int vis[200004];
int ans;

int d(){
    int sum=b[1];
    for(int i=2;i<=m;i++){
        sum=sum&b[i];
        //cout<<sum<<endl;
    }
    return sum;
}

void show(){
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
}

void search(int t){
    if(t>m){
        //cout<<sum<<endl;
        //show();
        ans=max(ans,d());
        //cout<<d()<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        b[t]=a[i];
        vis[i]=1;
        search(t+1);
        b[t]=0;
        vis[i]=0;
    }

}


signed main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    //for(int i=1;i<=n;i++){
    //    cout<<a[i]<<" ";
    //}
    //cout<<(2&3)<<endl;
    search(1);
    cout<<ans;
    return 0;
}
