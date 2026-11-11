#include <bits/stdc++.h>
using namespace std;
int dp[500005],a[500005],d[500005],v[500005],lst[500005];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        memset(d,0,sizeof d);
        memset(lst,0,sizeof lst);
        for(int i=k;i<=n;i++){
            d[a[i]]++;
            if(lst[a[i]]>0){
                for(int j=lst[a[i]];j<i;j++) d[a[j]]--;
            }
            lst[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            if(d[i]>0){
                dp[i]++;
            }

        }
    }
    for(int i=1;i<=m;i++) cout<<dp[i]<<' ';
}
