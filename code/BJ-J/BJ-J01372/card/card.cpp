#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n;
    int m;
    cin>>n>>m;
    int a1;
    int cnt=0;
    int a[500001]={};
    int ans[500001]={};
    for(int q=1;q<=n;q++){
            cin>>a1;
        cnt+=1;
        for(int i=1;i<=cnt;i++){
            if(a1==a[i]){
                for(int j=i;j<=cnt;j++){
                    a[j]=0;
                }
            }
        }
            a[cnt]=a1;
            for(int i=1;i<=cnt;i++){
                ans[a[i]]++;
            }
    }
      for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
return 0;
}
