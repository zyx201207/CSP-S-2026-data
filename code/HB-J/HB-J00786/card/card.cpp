#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005],ans[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int j=1,c=n;
    while(n--){
        int k=j-1;
        int h=0;
        for(int i=k;i<=c;i++){
            for(int v=0;v<i;v++){
                if(b[v]==a[i]){
                        h=v;
                  for(int x=v;x<=i;x++){
                    b[x]={};
                  }
                  break;
                }
            }
            b[h]=a[i];
        h++;
        }
        int f[100005]={0};
        for(int i=0;i<h;i++){
            for(int v=1;v<=m;v++){
                if(b[i]==v&&f[v]==0){
                        ans[v]++;
                f[v]=1;
                }
            }
        }
        j++;
        for(int i=0;i<h;i++){
            b[i]={};
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
