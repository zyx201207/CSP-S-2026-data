#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],s[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(s,0,sizeof(s));
        for(int j=i;j<=n;j++){
                s[j]=a[j];
            for(int k=j-1;k>=1;k--){
                if(s[j]==s[k]){
                    for(int l=k;l<j;l++){
                        s[l]=0;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            ans[s[j]]+=1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
