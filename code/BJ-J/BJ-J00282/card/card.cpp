#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],tnt[300005],num[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int t=0;
        for(int j=i;j<=n;j++){
            for(int k=1;k<=t;k++){
                if(num[k]==a[j]){
                    t=k-1;
                    break;
                }
            }
            num[++t]=a[j];
        }
        for(int j=1;j<=t;j++){
            tnt[num[j]]++;
        }
        memset(num,0,sizeof(num));
    }
    for(int i=1;i<=m;i++){
        cout<<tnt[i]<<" ";
    }
    return 0;
}
