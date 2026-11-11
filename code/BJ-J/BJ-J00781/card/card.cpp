#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    long long n , m;
    cin >> n >> m;
    vector<long long> v(n , 0);
    for(long long i = 0;i < n; i ++){
        cin >> v[i];
    }
    vector<long long> ans(m + 1 , 0);
    for(long long i = 0;i < n;i ++){
        string s = "";
        for(long long j = i;j < n;j ++){
            long long next = v[j];
            long long t = -1;
            for(long long k = 0;k < s.size();k ++){
                if((s[k] - '0') == next){
                    t = k;
                    break;
                }
            }
            if(t != -1){
                s = s.substr(0 , t + 1);
            } else {
                s += (next + '0');
            }
        }
        for(long long j = 0;j < s.size();j ++){
            ans[(s[j] - '0')] ++;
        }
    }
    for(long long i = 0;i < m;i ++){
        cout << ans[i + 1] << ' ';
    }
    return 0;
}
