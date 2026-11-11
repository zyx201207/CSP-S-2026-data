#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
constexpr int N = 5e5+10;
int n, m, a[N];
set<int> st;
int ton[N], pos[N];
int ans[N];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", a+i);
    for(int i = 1; i <= n; ++i){
        st.clear();
        for(int j = 1; j <= m; ++j) pos[j] = ton[j] = 0;
        for(int j = i; j <= n; ++j){
            if(pos[a[j]] != 0){
                for(int k = pos[a[j]]; k < j; ++k)
                    st.erase(a[k]), pos[a[k]] = 0, ton[a[k]] -= 1;
            }
            st.insert(a[j]);ton[a[j]] += 1;
            pos[a[j]] = j;
        }
        for(const auto &it : st) ans[it] += 1;
    }
    for(int i = 1; i <= m; ++i) printf("%d ", ans[i]);
    return 0;
}
