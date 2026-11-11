#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>

#define ll long long

const ll INF = (ll)1e12 + 10;

ll n, m, min = INF, max = -INF, t;
std::vector<ll> a;
int main(int argc, char **argv){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++){
        std::cin >> t;
        a.push_back(t);
        min = std::min(a[i], min);
        max = std::max(a[i], max);
    }
    double start = clock();
    std::sort(a.begin(), a.end());
    
    //for(const ll &t : a) std::cout << t << ' ';
    //std::cout << '\n';

    ll MAX = max + m;

    ll ans = 0, cnt, l, mt = m;
    //先选择一个要达到的目标
    for(ll goal = min; goal <= MAX; goal++){
        //贪心求出最多有多少个能达到相同
        m = mt;
        cnt = 0;
        l = std::upper_bound(a.begin(), a.end(), goal) - a.begin();

        //std::cout << "\n{\n goal : " << i << "\n idx : " << l << "\n num : \n";
        for(int j = l; j >= 0; j--){
            if(a[j] == goal) cnt++;
            else if(a[j] < goal && m > 0 && m + a[j] >= goal){
                m -= goal - a[j];
                cnt++;
            }else if(m + a[j] < goal) break;
            //std::cout << "  a[" << j << "] : " << a[j] << "  m : " << m << "  cnt : " << cnt << '\n';
        }
        //std::cout << "\n ans : " << ans << "\n cnt : " << cnt << "\n}\n";
        ans = std::max(ans, cnt);
        //把结果擂台求出最大值
    }

    std::cout << ans << '\n';
    
    std::cout << (clock() - start) / 1000000.0 << '\n';

    return 0;
}