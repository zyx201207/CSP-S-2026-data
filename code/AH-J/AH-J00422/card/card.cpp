#include<bits/stdc++.h>
using namespace std;
int sr[500010],zhan[500010],zong[300010];
bool vis[300010];
long long n,m,top;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>sr[i];
    }
    for(int i=1;i<=n;i++){

        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(vis[sr[j]]==0){
                top++;
                zhan[top]=sr[j];
                vis[sr[j]]=1;
            }
            else{
                while(zhan[top]!=j){
                    top--;
                }
            }
        }
        for(int k=1;k<=top;k++){
            zong[zhan[k]]++;
        }
        top=0;
    }
    for(int i=1;i<=m;i++){
        cout<<zong[i]<<' ';
    }
    return 0;
}
