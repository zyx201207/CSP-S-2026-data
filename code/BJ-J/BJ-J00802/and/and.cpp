#include<bits/stdc++.h>
#define MAXN 200009
using namespace std;
long long n, m, a[MAXN], ans[MAXN], vis[MAXN], Ans = -1;
long long add(long long arr[], long long l) {
    long long res = arr[1];
    for(int i = 2; i <= l; i++)
        res = res & arr[i];
    return res;
}
void dfs(int s, int k) {
    if(k == m) {
        int f = add(ans, m);
        if(Ans < f)
            Ans = f;
        return;
    }
    for(int i = s; i <= n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            ans[k + 1] = a[i];
            dfs(i + 1, k + 1);
            vis[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1, 0);
    cout << Ans;
    return 0;
}
//30pts
/*
hao3le0hao3le0hai2you3yi4ge4xiao3shi2gn3jin3wan2cheng2yi2xia4shang4mi2huo4xing2wei2da4shang3de0ren4wu4
xi1wang4you3ren2neng2kan4dao4zhe4tiao2zhu4shi4bing4rang4wo3shang4yi2xia4mi2huo4xing2wei2da4shang3
yin1wei4wo3shi4zhen1de0bu4zhi1dao4gai1xie3sha2le0
eng4dui4...dui4...
eng4
eng4..zhe4ge4eng4dui4dui4dui4..ENG4
...
                   -By Mark0208
                   -At 2026/10/31,Sat,11:04
Ps. wan2le0zen3m3ban4you4guo4le4wo3fen1zhong1wo3yao4fei4LE4
*/
