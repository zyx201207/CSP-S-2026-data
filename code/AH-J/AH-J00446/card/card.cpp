#include<bits/stdc++.h>
using namespace std;
int n,m,s[300005],x[300005],a[300005];
bool vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int k=1;k<=n;k++){
        memset(vis,0,sizeof(vis));
        memset(s,0,sizeof(s));
        int cnt=0;
        for(int i=k;i<=n;i++){
            if(!vis[x[i]]){
                s[++cnt]=x[i];
                vis[x[i]]=1;
            }else{
                bool f=0;
                for(int j=1;j<=cnt;j++){
                    if(s[j]==x[i]){
                        f=1;
                        vis[x[i]]=0;
                        s[j]=0;
                        cnt--;
                    }
                    if(f){
                        vis[s[j]]=0;
                        s[j]=0;
                        cnt--;
                     }
                }
                s[++cnt]=x[i];
                vis[x[i]]=1;
            }
        }
        //cout<<k<<endl;
        for(int j=1;j<=cnt;j++){
            a[s[j]]++;
            //cout<<s[j]<<" "<<a[s[j]]<<endl;
        }
    }
    for(int i=1;i<=m;i++) cout<<a[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
