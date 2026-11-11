#include <bits/stdc++.h>
using namespace std;

int a[500005],ans[300005],cnt[300005];

void refresh(){
    for(int i=1;i<=n;i++){
        cnt=0;
    }
    for(int i=1;i<=n;i++){
        cnt[a[i]]++;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            cnt[a[j]]++;
            if(cnt[a[j]]==1){

            }
        }
        refresh();
        cnt[a[i]]--;
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
