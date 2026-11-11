#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],a1[500010],cnt[300010],cnt2[300010],ans[300010],ing[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a1[i]=a[i];
        cnt[a[i]]++;
        cnt1[a[i]]++;
    }
    for(int i=1;i<=n;i++){
            int k=1;
        for(int j=i;j<=n;j++){
                if(a[j]==0)
                continue;
            if(cnt1[a[j]==1){
                ing[k]=a[j];
                cnt1[a[j]]--;
                k++;
            }
            else{
                for(int g=k;g>=1;g--)
                    a1[g]=0;
            }
        }
    }
    return 0;
}
