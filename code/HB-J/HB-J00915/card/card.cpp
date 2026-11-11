#include<bits/stdc++.h>
using namespace std;
unsigned long long a[500005],p[500005],ans[500005];
bool check[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    unsigned long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(check,0,sizeof(check));
        memset(p,0,sizeof(p));
        for(int j=i;j<=n;j++){
            if(check[a[j]]==0){
                check[a[j]]=1;
                p[a[j]]=j;
            }else{
                for(int k=p[a[j]];k<=j-1;k++){
                    check[a[k]]=0;
                    p[a[k]]=0;
                }
                check[a[j]]=1;
                p[a[j]]=j;
            }
        }
        for(int j=i;j<=n;j++){
            if(check[a[j]]==1){
                check[a[j]]=0;
                ans[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
