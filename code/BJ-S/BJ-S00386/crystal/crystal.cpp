#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6;
int n,m,a[N],ans,maxn;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if(n <= 5000){
        int num = 0;
        for(int i = 1;i <= n;i++){
            ans = 0,num = 0;
            for(int j = i;j >= 1;j--){
                if(num + a[i] - a[j] <= m){ num += a[i] - a[j]; ans ++;}
                else {
                    maxn = max(maxn,ans);
                    break;
                }
                maxn = max(maxn,ans);
            }
            maxn = max(maxn,ans);
        }
        cout << maxn;
    }
    else{
        if(a[1] == a[2]) cout << n;
        else{
            int x = a[2] - a[1];
            int ans = x,num = 0;
            while(m >= 0){
                m -= ans;
                ans += x;
                num ++;
            }
            cout << num;
        }
    }
}

