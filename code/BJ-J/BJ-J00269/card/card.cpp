#include<bits/stdc++.h>
using namespace std;
int a[500005],app[300005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            app[a[j]]++;
            if(app[a[j]]>1){
                int b;
                for(int k=j;k>0;k--){
                    if(a[j]==a[k]){
                        b=k;
                        break;
                    }
                }
                for(int k=b;k<j;k++){
                    app[a[k]]--;
                }
            }
        }
        for(int j=1;j<=m;j++){
            ans[j]+=app[j];
            app[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[j]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
