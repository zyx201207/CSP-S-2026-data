#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int x[100005];
        for(int j=1;j<=n;j++) x[j]=0;
        for(int j=1;j<=i;j++) x[j]=a[j];
        for(int j=1;j<=i;j++){
            for(int o=1;o<=j;o++){
                if(x[o]==x[j]){
                    for(int q=o;q<j;q++) x[q]=0;
                }
            }
        }
        for(int j=1;j<=i;j++){
            for(int o=1;o<=m;o++){
                if(x[j]==o){
                    ans[o]++;
                    continue;
                }
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
