#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=2e5+500,L=30;
ll n,m,a[N],ans=0;
bool vis[N]={0};

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int x=1;x<=n;x++){
        cin>>a[x];
    }
    for(int k=30;k>=0;k--){
        ll t=(1LL<<(ll)k);
        int cnt=0;
        for(int x=1;x<=n;x++){
            if(vis[x]==0 && a[x]&t){
                cnt++;
            }
        }
        if(cnt>=m){
            ans+=t;
            //cout<<cnt<<endl;
            for(int x=1;x<=n;x++){
                if(vis[x]==0 && (a[x]&t)==0){
                    vis[x]=1;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/