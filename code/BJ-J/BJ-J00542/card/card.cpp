#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],ans[300005];
bool b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int pos[300005],c[500005];
        for(int j=i;j<=n;j++){
            if(b[a[j]]==1){
                for(int k=pos[a[j]];k<j;k++){
                    b[c[k]]=0;
                    pos[c[k]]=0;
                    c[k]=0;
                }
                c[j]=a[j];
                b[a[j]]=1;
                pos[a[j]]=j;
            }
            else{
                c[j]=a[j];
                b[a[j]]=1;
                pos[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++){
            if(b[j]) ans[j]++;
            b[j]=0;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}