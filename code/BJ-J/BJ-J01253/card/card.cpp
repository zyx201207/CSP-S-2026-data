#include<bits/stdc++.h>
using namespace std;
int a[500005];
int s[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[n];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            s[j]=0;
        }
        for(int j=i;j<=n;j++){
            for(int k=j;k>=i;k--){
                if(s[k]=a[j]){
                    for(int p=k;p<=j;p++){
                        s[p]=0;
                    }
                    break;
                }
            }
            for(int k=j;k>=i;k--){
                if(a[k]==0){
                    continue;
                }
                s[k]=a[j];
                break;
            }
            int ans=0;
            for(int k=j;k>=i;k--){
                if(s[k]==i){
                    ans++;
                }
            }
        }
        cout<<ans<<" ";
    }
    return 0;
}
