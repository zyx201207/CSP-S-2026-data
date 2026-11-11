#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
typedef long long i64;
constexpr int ms1 = 5e5 + 5;
using namespace std;

i64 n,m;
i64 a[ms1];
stack<i64> s1,s2;

inline bool cmp(i64 a,i64 b){
    return a < b;
}

void solve1(){
    i64 cnt,ans = 0,now = 0;
    for(int i = 1;i <= n;i++){
        //cout << i << "\n";
        for(int l = 1;l < i;l++){
            s1.push(a[i] - a[l]);
        }
        for(int r = n;r > i;r--){
            s2.push(a[r] - a[i]);
        }

        cnt = 1,now = 0;
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty() && !s2.empty()){
                now += min(s1.top(),s2.top());
                (s1.top() <= s2.top() ? s1.pop() : s2.pop());
                if(now > m){
                    break;
                }
                cnt++;
            }
            else if(s1.empty()){
                now += s2.top();
                s2.pop();
                if(now > m){
                    break;
                }
                cnt++;
            }
            else if(s2.empty()){
                now += s1.top();
                s1.pop();
                if(now > m){
                    break;
                }
                cnt++;
            }
        }
        ans = max(ans,cnt);

        while(!s1.empty()){
            s1.pop();
        }
        while(!s2.empty()){
            s2.pop();
        }
    }
    cout << ans;
}

void solve2(){
    int i = n/2;
    i64 cnt,ans = 0,now = 0;
    for(int l = 1;l < i;l++){
        s1.push(a[i] - a[l]);
    }
    for(int r = n;r > i;r--){
        s2.push(a[r] - a[i]);
    }

    cnt = 1,now = 0;
    while(!s1.empty() || !s2.empty()){
        if(!s1.empty() && !s2.empty()){
            now += min(s1.top(),s2.top());
            (s1.top() <= s2.top() ? s1.pop() : s2.pop());
            if(now > m){
                break;
            }
            cnt++;
        }
        else if(s1.empty()){
            now += s2.top();
            s2.pop();
            if(now > m){
                break;
            }
            cnt++;
        }
        else if(s2.empty()){
            now += s1.top();
            s1.pop();
            if(now > m){
                break;
            }
            cnt++;
        }
    }
    cout << cnt;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    sort(a+1,a+n+1,cmp);

    if(n <= 5000) solve1();
    else solve2();
    return 0;
}
