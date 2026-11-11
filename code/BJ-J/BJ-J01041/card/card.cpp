#include<bits/stdc++.h>
using namespace std;
int a[20005],b[20005],s[20005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=i;
    }
    int se;
    for(int i=2;i<=n-1;i++){
        se=0;
        for(int j=i+1;j<=n;j++){
            for(int k=i-1;k>=0;k--){
                if(a[j]==a[k]){
                    b[i]=j-k-1;
                    se=1;
                    break;
                }

            }
            if(se==1){
                break;
            }
        }
    }
    for(int i=1;i<=m;i++){
       for(int j=1;j<=n;j++){
            if(a[j]==i){
                s[i]=max(s[i],b[j]);
            }
       }
    }
    for(int i=1;i<=m;i++){
        if(s[i]==1){
                s[i]=0;
            for(int j=1;j<=n;j++){
                if(a[j]==i){
                    s[i]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }

}
