#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long s1[114514];
long long s2[114514];
long long w[1000010];
map<long long,int> mp1;
map<long long,int> mp2;
vector<long long> zhong;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++) cin >> w[i];
    long long k,a,t;
    cin >> k;
    for(long long i = 1;i <= k;i ++){
        cin >> a >> t;
        s1[a] = t;
        mp1[a] = true;
    }
    if(n == 1){
        while(q--){
            long long x,y;
            cin >> x >> y;
            cout << w[x] + w[y] + s1[x] + s1[y];
        }
    }else{
        cin >> k;
        for(long long i = 1;i <= k;i ++){
            cin >> a >> t;
            s2[a] = t;
            mp2[a] = true;
            if(mp1[a]) zhong.push_back(a);
        }
        long long ans = 1e18;
        for(int i = 0;i < (int)zhong.size();i ++){
            ans = min(s1[zhong[i]] + s2[zhong[i]],ans);
        }
        while(q--){
            long long x,y;
            cin >> x >> y;
            cout << w[x] + w[y] + s1[x] + s2[y] + ans;
        }
    }
}
