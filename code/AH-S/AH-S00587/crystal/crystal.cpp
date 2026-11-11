#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

long long n, m;
long long a[500005], d[500005];
bool flagA=0, flagB=0;

int answer(int id){
    long long sum = m;
    long long cnt = 1;
    long long ed[500005];
    for(int i=1; i<=n; i++){
        ed[i] = d[i];
    }
    for(int i=id; i>=2; i--){
        if(sum >= ed[i]){
            cnt++;
            sum -= ed[i];
            ed[i-1]+=ed[i];
            ed[i]-=ed[i];
        }
        if(sum<ed[i-1] || sum==0){
            break;
        }
    }
    return cnt;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(a[i]!=i){
            flagA = 1;
        }
        if(i>=3 && a[i]-a[i-1] != a[i-1]-a[i-2]){
            flagB = 1;
        }
    }
    if(!flagA){
        int op=0, ans=0;
        while(m>=op){
            m-=op;
            op++;
            ans ++;
        }
        if(ans > n) ans = n;
        cout << ans;
    }else if(!flagB){
        int x = a[2]-a[1];
        int op=0, ans=0;
        while(m>=op){
            m-=op;
            op+=x;
            ans ++;
        }
        if(ans > n) ans = n;
        cout << ans;
    }else{
        sort(a+1, a+n+1);
        for(int i=1; i<=n; i++){
            d[i] = a[i]-a[i-1];
        }
        int ans = -1;
        for(int i=n; i>=2; i--){
            ans = max(ans, answer(i));
            if(ans >= i){
                break;
            }
        }
        cout << ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
 }
