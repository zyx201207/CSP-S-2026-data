#include<bits/stdc++.h>
using namespace std;
long long n,m,t=1;
long long a[500005];
long long d[300005][2]={};
long long ans[300005]={0};
long long que[9999999]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
            int l=0;
        for(int i=k;i<=n;i++){

            if(d[a[i]][0]==0){
                que[++l]=a[i];
                d[a[i]][0]=1;
                d[a[i]][1]=l;
            }else if(d[a[i]][0]==1){
                for(int j=d[a[i]][1]+1;j<=l;j++){
                    d[a[j]][0]=0;
                    que[j]=-1;
                }
            }


        }
        for(int j=1;j<=m;j++){
            if(d[j][0]==1) ans[j]++;
            d[j][0]=0;
            d[j][1]=0;
        }
        for(int j=1;j<=l;j++){
            que[j]=0;
        }

    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
