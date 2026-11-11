#include <bits/stdc++.h>
using namespace std;
int n,m,a[510000],ans[310000],card[510000],st;
bool vis[310000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        st=0;
        memset(card,-1,sizeof(card));
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
                st++;
                card[st]=a[j];
                vis[a[j]]=1;
            }
            else {
                int k,sts=st;
                bool flag=0;
                for(k=1;k<=st;k++){
                    if(card[k]==a[j]) flag=1;
                    if(flag==1){
                        vis[card[k]]=0;
                        card[k]=-1;
                        sts--;
                    }
                }
                st=sts;
                st++;
                card[st]=a[j];
                vis[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++){
            if(vis[j]) ans[j]++;
        }
    }
    for(int j=1;j<=m;j++){
        cout<<ans[j]<<' ';
    }
	return 0;
}
