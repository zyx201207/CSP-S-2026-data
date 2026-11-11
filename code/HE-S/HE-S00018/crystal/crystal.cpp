#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace qwq {
    static vector<int> a;
    static int n,m,max_ai = -1e12-10,min_ai = 1e12+10;
    static int calc(const int target) noexcept{
        int cur = m;
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] > target) {
                break;
            }
            if(a[i] == target){
                cnt++;
                continue;
            }
            int wanted = target - a[i];
            if(cur - wanted >= 0){
                cur -= wanted;
                cnt++;
            }else{
                break;
            }
        }
        #ifdef QwQ_DEBUG
        cout << "[dbg] target=" << target << ", cnt=" << cnt << endl;
        #endif // QwQ_DEBUG
        return cnt;
    }
    static bool check(const int target) noexcept{
        //return target >= 2;
        int cnt = calc(target);
        bool ans = true;
        for(int i = target+1;i <= max_ai;i++){
            if(calc(i) > cnt){
                ans = false;
                break;
            }
        }
        #ifdef QwQ_DEBUG
        cout << "[dbg] target=" << target << " ok=" << (ans) << endl;
        #endif // QwQ_DEBUG
        return ans;
    }
    static void main() noexcept{
        cin >> n >> m;
        a.resize(n+1);
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            max_ai = max(max_ai,a[i]);
            min_ai = min(min_ai,a[i]);
        }
        sort(a.begin()+1,a.end());
        #ifdef QwQ_DEBUG
        cout << "[dbg] ";
        for(const auto num : a){
            cout << num << " ";
        }
        cout << endl;
        #endif // QwQ_DEBUG
        int l = min_ai,r = max_ai;
        while(l < r){
            int mid = (l+r) / 2;
            if(check(mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        cout << calc(l) << "\n";
    }
}
signed main() noexcept{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    qwq::main();
    return 0;
}
/*
#include <bits/stdc++.h>
#define int long long
#define QwQ_DEBUG
using namespace std;
namespace qwq {
    static vector<int> a;
    static int n,m,max_ai = -1e12-10,min_ai = 1e12+10;
    static void main() noexcept{
        cin >> n >> m;
        a.resize(n+1);
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            max_ai = max(max_ai,a[i]);
            min_ai = min(min_ai,a[i]);
        }
        sort(a.begin()+1,a.end());
        #ifdef QwQ_DEBUG
        cout << "[dbg] ";
        for(const auto num : a){
            cout << num << " ";
        }
        cout << endl;
        #endif // QwQ_DEBUG
        int last_can = -1;
        for(int target = min_ai;target <= max_ai;target++){
            int cur = m;
            int cnt = 0;
            for(int i = 1;i <= n;i++){
                if(a[i] > target) {
                    break;
                }
                if(a[i] == target){
                    cnt++;
                    continue;
                }
                int wanted = target - a[i];
                if(cur - wanted >= 0){
                    cur -= wanted;
                    cnt++;
                }else{
                    break;
                }
            }
            #ifdef QwQ_DEBUG
            cout << "[dbg] target=" << target << ", cnt=" << cnt << ", last_can=" << last_can << endl;
            #endif // QwQ_DEBUG
            if(cnt < last_can){
                cout << last_can << "\n";
                return;
            }
            last_can = cnt;
        }
    }
}
signed main() noexcept{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    qwq::main();
    return 0;
}
*/
