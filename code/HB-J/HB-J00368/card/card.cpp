#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int n,m,a[200005],b[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=1+i;j<=n;j++){
            b[j-i]=a[j];
        }
        for(int j=1+i;j<=n;j++){
            int flag=0;
            for(int k=1;k<=n;k++){
                if(b[k]==a[j]){
                    flag=1;
                    for(int ii=k+1;ii<=n;ii++){
                        b[ii]=0;
                    }
                    break;
                }
            }
            if(!flag){
                for(int k=1;k<=n;k++){
                    if(b[k]==0){
                        b[k]=a[j];
                        break;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++)mp[b[j]]++;
    }
    for(int i=1;i<=m;i++){cout<<mp[i]<<" ";};
    return 0;
}
