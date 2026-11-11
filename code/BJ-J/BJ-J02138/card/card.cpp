#include<bits/stdc++.h>
using namespace std;
int n,m,a[200020],b[200020],c=0,ans[200020];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            c=0;
            for(int k=1;k<=j-i+1;k++){
                if(a[j]==b[k]){
                    c=1;
                    b[k]=0;
                }
                if(c==1){
                    b[k]=0;
                }
            }
            b[j-i+1]=a[j];
        }
        for(int i=1;i<=n-c;i++){
            ans[b[i]]++;
            b[i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
