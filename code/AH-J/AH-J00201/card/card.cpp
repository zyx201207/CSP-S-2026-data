#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],b[1000005],ans[1000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++){
            if(b[a[j]]==0){
                b[a[j]]=j;
            }else{
                for(int k=b[a[j]];k<=j;k++){
                    b[a[k]]=0;
                }
                b[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++){
            if(b[j]){
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
