#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mai;
int a[300005];
vector<int>anss;
void dfs(int st,int k,int cnt){
    if(k == m){
        anss.push_back(cnt);
        return;
    }
    for(int i = st+1;i <= n;i++){
        dfs(i,k+1,cnt&a[i]);
    }

}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n >>m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        mai = max(mai,a[i]);
    }
    if(n <= 20){
        int ans = 0;
        for(int i = 1;i <= n-m+1;i++){
            dfs(i,1,a[i]);
        }
        for(int i = 1;i <= anss.size();i++){
            ans = max(ans,anss[i]);
        }
        cout <<ans;
        return 0;
    }
    if(n <= 2000){
        if(m == 1){
            int ans = 0;
            for(int i = 1;i <= n;i++){
                ans = max(ans,a[i]);
            }
            cout <<ans;
            return 0;
        }else if(m == n){
            int ans = a[1];
            for(int i = 2;i <= n;i++){
                ans &= a[i];
            }
            cout <<ans;
            return 0;
        }else if(m == 2){
            int ans = 0;
            for(int i = 1;i <= n-m+1;i++){
                dfs(i,1,a[i]);
            }
            for(int i = 1;i <= anss.size();i++){
                ans = max(ans,anss[i]);
            }
            cout <<ans;
            return 0;
        }
    }
    if(mai < 4){
        int cnt1 = 0,cnt2 = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] == mai){
                cnt2++;
            }else{
                cnt1++;
            }
        }
        if(cnt2 >= m){
            cout << 2;
            return 0;
        }else{
            cout <<0;
            return 0;
        }
    }
    return 0;
}
