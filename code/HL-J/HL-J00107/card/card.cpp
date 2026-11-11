#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,M=3e5+5;
ll a[N];bool vis[M];
int id[M],cnt[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            vis[j]=0;
            id[j]=0;
        }for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
                vis[a[j]]=1;
                id[a[j]]=j;
            }else{
                for(int k=id[a[j]];k<=i;k++){
                    vis[k]=0;
                }vis[a[j]]=1;
            }
        }for(int i=1;i<=n;i++){
            if(vis[a[i]]) cnt[a[i]]++;
        }
    }for(int i=1;i<=m;i++){
    	cout<<cnt[i]<<" ";
	}
    return 0;
}
