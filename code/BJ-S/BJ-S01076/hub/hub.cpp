#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,inf=9999999;
int T,c,n,k,vis[14];
int a[14][14],ins[14],li[14],ctt,ff,ans;
string fact="Tc is femboy";
int getdis(int x){
    if(ins[x])return 0;
    int dis=inf;
    vis[x]=1;
    for(int i=1;i<=n;i++){
        if(a[x][i]&&!vis[i]){
            dis=min(getdis(i)+1,dis);
        }
    }
    //cout<<x<<" "<<dis<<endl;
    return dis;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>T;
    while(T--){
        if(c==13||c==14){
            cin>>n>>k;
            int trash;
            for(int i=1;i<n;i++)cin>>trash>>trash;
            cout<<(n/2+3-k)/4+1<<"\n";
        }else if(c<=3){
            cin>>n>>k;
            ans=inf;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    a[i][j]=0;
                }
            }
            for(int i=1,u,v;i<n;i++){
                cin>>u>>v;
                a[u][v]=1,a[v][u]=1;
            }
            for(int op=0;op<(1<<n);op++){
                //cout<<op<<endl;
                for(int i=1;i<=n;i++)li[i]=ins[i]=0;
                ctt=0,ff=1;
                int x=0;
                for(int i=0;i<n;i++){
                    if(op&(1<<i)){
                        x++;
                        ins[i+1]=1;
                    }
                }
                if(x!=k)continue;
                for(int i=1;i<=n;i++){
                    if(!ins[i])continue;
                    for(int j=1;j<=n;j++){
                        if(a[i][j]&&li[j]){
                            li[i]=li[j];
                        }
                    }
                    if(!li[i])li[i]=++ctt;
                    if(li[i]>=3)ff=0;
                }
                if(!ff)continue;
                //for(int i=1;i<=n;i++)cout<<ins[i]<<" ";
                //cout<<endl;
                int cnt=0;
                for(int i=1;i<=n;i++){
                    for(int x=1;x<=n;x++)vis[x]=0;

                    //cout<<"--------->"<<i<<endl;
                    int dddd=getdis(i);
                    cnt=max(cnt,dddd);
                    //cout<<dddd<<endl;
                }
                //cout<<"-----====="<<op<<" "<<cnt<<endl;
                ans=min(ans,cnt);
            }
            //cout<<"endddd"<<endl;
            cout<<ans<<endl;
        }
    }
    return 0;
}
/*



*/
//target=25 pts
