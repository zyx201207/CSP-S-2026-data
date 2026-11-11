#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],cnt[500005],vis[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,x=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
        int x=0;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]!=0){
                for(int k=vis[a[j]];k<=x;k++){
                    vis[b[k]]=0;
                    b[k]=0;
                }
                x=vis[a[j]];
            }else{
				vis[a[j]]=++x;
                b[x]=a[j];
            }
        }
        for(int j=1;j<=x;j++){
			cnt[b[j]]++;
		}
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
