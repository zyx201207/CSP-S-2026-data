#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n,m;
int a[N],box[N];
int ans;

void dfs(int cur){
    if(cur > n){
        int sum = 0,cnt = 0;
        for(int i = 1;i<=n;i++){
            if(box[i]){
                if(cnt == 0){
                    sum = a[i];
                }
                sum = (sum & a[i]);
                cnt++;
            }
        }
        if(cnt == m){
            ans = max(ans,sum);
        }
        return ;
    }
    for(int i = 0;i<=1;i++){
        box[cur] = i;
        dfs(cur+1);
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    if(m == 1){
        for(int i = 1;i<=n;i++){
            ans = max(ans,a[i]);
        }
    }else if(m == 2){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i == j){
                    continue;
                }
                ans = max(ans,(a[i]&a[j]));
            }
        }
    }else if(m == n){
        for(int i = 1;i<=n;i++){
            if(i == 1){
                ans = a[i];
            }
            ans = (ans & a[i]);
        }
    }else{
        dfs(1);
    }
    cout << ans;
    return 0;
}
