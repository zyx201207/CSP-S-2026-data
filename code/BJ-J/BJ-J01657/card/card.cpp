#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+7;
long long m,n,xu;
bool vis[N];
long long a[N],shun[N],shu[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int z=1;z<=n;z++){
        cin>>shun[z];
    }
    for(int z=1;z<=n;z++){
        for(int i=1;i<5e5+7;i++){
            a[i]=0;
            vis[i]=0;
        }
        for(int i=1;i<=n-z+1;i++){
            a[i]=shun[z+i-1];
            if(!vis[a[i]]) vis[a[i]]=1;
            else{
                xu=i;
                while(xu--){
                    if(a[xu]!=a[i]){
                        vis[a[xu]]=0;
                        a[xu]=0;
                    }
                    else{
                        a[xu]=0;
                        break;
                    }
                }
            }

        }
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                continue;
            }
            else{
                shu[a[i]]++;
            }
        }
    }

    for(int i=1;i<=m;i++){
        if(shu[i]==0){
           continue;
        }
        else{
            cout<<shu[i]<<" ";
        }
    }
    return 0;
}


