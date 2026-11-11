#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[514514],diff[514514],ans = 1,sum,sumj;
deque<int> q;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 2;i <= n;i++){
        diff[i] = a[i] - a[i-1];
    }
    for(int i = 2;i <= n;i++){
        q.push_back(i);
        sum += q.size()*diff[i];
        sumj += diff[i];
        //cout << sum << " " << q.size() << endl;
        while(!q.empty() && sum > m){
            sum -= sumj;
            sumj -= diff[q.front()];
            //cout << q.size()*diff[q.front()] << endl;
            q.pop_front();
        }
        //cout << (int)q.size() << endl;
        if(sum <= m) ans = max(ans,(int)q.size()+1);

    }
    cout << ans;
    return 0;
}
