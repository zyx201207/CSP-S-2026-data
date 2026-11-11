#include<bits/stdc++.h>
using namespace std;
int m,n,card[500005],z[500005],x,t,y,ans[300005],b;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    for(int i=1;i<=n;i++){
        z[1]=card[i];
        t=0;
        for(int j=i;j<=n;j++){
            b=0;
            x=card[j];
            for(int k=1;k<=t;k++){
                if(z[k]==x){
                    t=k;
                    b=1;
                }
            }
            if(b==0){
                t++;
                z[t]=x;
            }
        }
        for(int j=1;j<=t;j++){
            ans[z[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

