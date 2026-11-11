#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],ans[500005],ans2[500005],ans3[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(ans2,0,sizeof ans2);
        memset(ans3,0,sizeof ans3);
        for(int j=i;j<=n;j++){
            ans2[j]=1;
        }
        for(int j=i;j<=n;j++){
            ans3[a[j]]++;
            if(ans3[a[j]]==2){
                int k=j-1;
                while(a[k]!=a[j]){
                    if(ans2[k]==0) {
                        k--;
                        continue;
                    }
                    ans2[k]=0;
                    ans3[a[k]]--;
                    k--;
                }
                //cout<<k<<endl;
                ans2[k]=0;
                ans3[a[k]]--;
            }
        }
        for(int j=1;j<=n;j++){
            //cout<<ans2[j]<<" ";
            if(ans2[j]) ans[a[j]]++;
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
