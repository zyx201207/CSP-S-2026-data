#include<bits/stdc++.h>
using namespace std;
int k[500005],l[500005],js[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
                l[j]=k[j];
           for(int o=1;o<j;o++){
                if(l[j]==l[o]){
                    for(int f=o;f<=j;f++){
                        l[f]=0;
                    }
                        l[o]=k[j];

                    }
           }
        }
        for(int j=1;j<=m;j++){
            for(int u=1;u<=n;u++){
                    //cout<<l[u]<<" ";
                if(j==l[u]){
                    js[j]++;
                    //cout<<k[u]<<" "<<j<<" ";
                    break;
                }
            }
        }
        for(int j=1;j<=n;j++){
            //cout<<l[j]<<" ";
            l[j]=0;
        }
        //cout<<endl;

    }
    for(int i=1;i<=m;i++){
        cout<<js[i]<<" ";
    }
    //cout<<1;
    return 0;
}
