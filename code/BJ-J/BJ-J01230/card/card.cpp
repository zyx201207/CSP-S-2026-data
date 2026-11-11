#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int n,m;
int a[maxn],ans[maxn];
bool b[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        memset(b,0,sizeof(b));
        for(int i=k;i<=n;i++){
            if(b[a[i]]==1){
                for(int j=k;j<=i-1;j++){
                    b[a[j]]=0;
                }
            }
            b[a[i]]=1;
        }
        for(int i=1;i<=m;i++){
            if(b[i]) ans[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
