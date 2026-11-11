#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int b[500010];
int g[500010];
int k[500010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            b[a[i]]++;
            if(a[n]!=a[i]) b[a[n]]++;
        }
        cout<<b[1]<<" "<<b[2];
        return 0;
    }
    for(int i=1;i<=n;i++){
      //  int l=1;
       // memset(g,0,sizeof(g));
       // memset(k,0,sizeof(k));
      //  for(int j=i;j<=n;j++){
       //     if(k[a[j]]==0){
      //          g[l]=a[j];
       //         k[a[j]]=l;
       //         l++;
       //     }else{
       //         for(int s=k[a[j]]+1;s<=l;s++){
       //             k[g[s]]=0;
       //         }
       //         l=k[a[j]]+1;
       //     }
       // }
       // for(int j=1;j<=l;j++){
       //     b[g[j]]++;
       // }
        memset(g,0,sizeof(g));
        int l=1;
        for(int j=i;j<=n;j++){
            bool flag=0;
            int l_=l-1;
            for(int h=1;h<=l_;h++){
                if(flag==1){
                    g[h]=0;
                    l=h;
                }
                if(g[h]==a[j]){
                    flag=1;
                }
            }
            if(flag==0){
                g[l]=a[j];
                l++;
            }
          //  cout<<l-1<<"\n";
         //   for(int h=1;h<=l-1;h++){
           //     cout<<g[h]<<" ";
          //  }
         //   cout<<"\n";
        }
        for(int j=1;j<=l;j++){
            b[g[j]]++;
        }
       // cout<<"\n";
    }
    for(int i=1;i<=m;i++) cout<<b[i]<<" ";
    return 0;
}
