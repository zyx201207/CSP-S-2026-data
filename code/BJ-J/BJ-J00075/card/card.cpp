#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],last[300005],num[50005];
bool f[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++){
        ans[a[i]]+=i;
            for(int j=last[a[i]];j<=i;j++){
                ans[a[j]]-=(num[last[a[i]]]+1)/2;
            }
        last[a[i]]=i,num[i]=num[last[a[i]]]+1;
    
    }
    for(int i=1;i<=m;i++)
        cout << ans[i] << " ";
    return 0;
}

