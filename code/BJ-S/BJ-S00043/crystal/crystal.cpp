#include<bits/stdc++.h>
using namespace std;
long long a[500005],m;
int n,ans = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    queue<long long>q;
    q.push(a[1]);
    long long nowm = 0;
    int in_que = 1;
    for(int i = 2;i <= n;i++){
        while(nowm + (a[i] - a[i - 1]) * in_que > m && in_que > 0){
            nowm = nowm - (a[i] - q.front());
            in_que --;
            q.pop();
        }
        nowm += (a[i] - a[i - 1]) * in_que;
        q.push(a[i]);
        in_que ++;
        ans = max(ans,in_que);
    }
    cout << ans;
    return 0;
}
