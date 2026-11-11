#include<bits/stdc++.h>
using namespace std;
int a[500000];
int b[500000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int ans = 0;
    int cnt;
    int m0;
    int cur;
    for(int i = 1;i < n;i++){
        for(int j = 0;j < n;j++){
            b[j] = a[j];
        }
        m0 = m;
        cnt = 0;
        for(int j = i;j < n;j++){
            if(a[i] == a[j]) cnt++;
        }
        cur = i-1;
        while(m0 > 0 && cur >= 0){
            if(b[cur] == b[i]){
                cur--;
                cnt++;
            }
            if(cur < 0) break;
            m0--;
            b[cur]++;
            if(b[cur] == b[i]){
                cur--;
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
