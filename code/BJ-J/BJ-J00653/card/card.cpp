#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005],ans[500005],cnt=0,count1[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int z = 1;z <= n; z ++){
        cnt = 0;
        for(int i = 1; i <= m; i ++) ans[i] = 0;
        for(int i = z; i <= n; i ++){
            for(int k = 1; k <= cnt; k ++){
                if(ans[k]==a[i]){
                    cnt = k-1;
                    break;
                }
            }
            ans[++cnt] = a[i];
        }
        for(int i = 1; i <= cnt; i ++){
            count1[ans[i]]++;
        }
    }
    for(int i=1; i <= m; i ++){
        cout << count1[i] << " ";
    }
    return 0;
}
