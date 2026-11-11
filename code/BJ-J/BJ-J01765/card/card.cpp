#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],z[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int q=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==2){
        int l=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
            {
                if(a[l]==a[j]){
                    l=j;
                }
            }
            ans[a[n]]++;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            int q=0,v=0;
            for(int j=i;j<=n;j++)
            {
                q=j-1;
                for(int k=1;k<j-q;k++)
                {
                    if(z[k]==a[j])
                    {
                        v=k;
                        break;
                    }
                }
                if(v)
                {
                    for(int k=v;k<j-q;k++)
                    {
                        z[k]=0;
                    }
                    q=j-v;
                    v=0;
                }
                z[j-q]=a[j];
            }
            for(int j=1;j<=n;j++){
                if(z[j]){
                    ans[z[j]]++;
                    z[j]=0;
                }
                else{
                    break;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
            if(ans[i]==0) continue;
        cout<<ans[i]<<" ";
    }
    return 0;
}
