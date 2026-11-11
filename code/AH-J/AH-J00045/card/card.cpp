#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005],g[500005],num[500005];

int ccard(int x,int ni,int nj){
    for(int i=1;i<=(nj-ni+1);i++){
        if(g[i]==x){
            return i;
        }
    }
    return 0;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=500005;j++){
            g[j]=0;
        }
        for(int j=i;j<=n;j++){
            int te=ccard(a[j],i,j);
            if(!te){
                g[j-i+1]=a[j];
            }else{
                for(int k=te+1;k<=(j-i+1);k++){
                    g[k]=0;
                }
            }
        }
        for(int j=1;j<=n;j++){
            num[g[j]]+=1;

        }

    }
    for(int i=1;i<=m;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}

