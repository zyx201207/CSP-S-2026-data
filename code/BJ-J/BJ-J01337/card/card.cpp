#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10;
int a[N];
bool f[N];
int ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        memset(f,false,sizeof(f));
        for(int j=i;j<=n;j++){
            for(int k=j-1;k>=i;k--){
                if(a[j]==a[k]&&!f[k]){
                    for(int l=k;l<j;l++){
                        f[l]=true;
                    }
                }
            }
        }
        for(int k=i;k<=n;k++){
            if(!f[k]){
                ans[a[k]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
