#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m, ans=-1; cin >> n >> m;
    bool k=1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        k = (a[i] == i+1 ? 1 : 0);
    }
    if(k){
        ans = 1;
        while(ans *(ans + 1) < 2 * m){
            if((ans+1) * (ans+2) > 2 * m) break;
            ans++;
        }
        cout << min(ans+1, n);
        return 0;
    }
    sort(a, a+n, greater<int>());
    vector<int> aa, bb;
    for(int i=0;i<n;i++){
        if(i == 0){
            aa.push_back(a[i]); bb.push_back(1);
        }else{
            if(a[i]==aa.back()) bb[bb.size()-1] += 1;
            else{
                aa.push_back(a[i]); bb.push_back(1);
            }
        }
    }
    n = aa.size();
    int cnt = 0;
    for(int i=0;i<n-1;i++){
        int val=0, sum=bb[i], ct=0;
        while(val <= m && ct < n-i-1){
            if(val + bb[i+ct+1] * (a[i] - a[i+ct+1]) <= m){
                ct++;
                val += bb[i+ct] * (a[i] - a[i+ct]);
                sum += bb[i+ct];
            }else if(val<m){
                ct++;
                sum += ((m-val) / (a[i] - a[i+ct]));
                break;
            }
        }
        ans = max(ans, sum);
        if(ans != sum) cnt++;
        if(n >= 5000 && cnt >= (int)(n / 2.718)) break;

    }

    cout << max(ans, bb[n-1]) << endl;
    return 0;

}
