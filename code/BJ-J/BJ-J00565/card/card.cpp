#include<bits/stdc++.h>
using namespace std;
int a[10000010],t[10000010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int pre=1;
    int tp=0;
    for(int x=1;x<=m;x++){
        for(int i=1;i<=n;i++){
            for(int j=pre++;j<=n;j++){
                for(int k=0;k<t;k++){
                    if(t[k]==a[j])tp=k;
                }
                t[tp++]=a[j];
                for(int j=0;j<tp;j++)if(t[j]==1)ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
