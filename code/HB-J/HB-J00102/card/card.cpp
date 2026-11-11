#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+2),b(n+2),ans(m+2);
    for(int i=1;i<=n;i++)cin>>a[i];
    int f=0;
    while(f<n){
        for(int i=1;i<=n-f;i++){
            b[i]=a[i+f];
        }
        for(int i=2;i<=n-f;i++){
            for(int j=i;j>=1;j--){
                if(b[j]!=-1){
                    if(b[j]==b[i]){
                        for(int k=j;k<i;k++){
                            b[k]=-1;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n-f;i++){
            if(b[i]!=-1)ans[b[i]]++;
        }
        f++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
