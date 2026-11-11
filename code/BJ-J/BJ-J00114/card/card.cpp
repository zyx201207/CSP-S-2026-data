#include<bits/stdc++.h>
using namespace std;
long long  a[1005],cnt[1005];
int main(){
    int n,m,ji=0,jii=0;
     freopen("card.in","r",stdin);
     freopen("card.out","w",stdout);
     cin>>n>>m;
     set<int> s;
     for(int i=1;i<=n;i++){
        cin>>a[i];
     }

     for(int i=1;i<=n;i++){
            int b[1005];
            for(int j=i;j<=n;j++){

             b[j]=a[j];
            }
           if(ji>=n){
            break;
           }
           for(int i=1;i<=n;i++){

            if(b[i]==ji){
                 cnt[ji]++;
            }
           }
           ji++;
     }
     for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
     }
     return 0;
}
