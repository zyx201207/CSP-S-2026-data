#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[100001],ans[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        long long b[100001],cnt=0;
        for(int j=i;j<=n;j++){
            bool is=1;
            for(int k=1;k<=cnt;k++){
                if(a[j]==b[k]){
                    is=0;
                    cnt=k;
                    break;
                }
            }
            if(is){
                cnt++;
                b[cnt]=a[j];
            }
        }
        for(int i=1;i<=cnt;i++){
            ans[b[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
