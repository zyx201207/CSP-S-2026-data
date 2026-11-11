#include<bits/stdc++.h>
using namespace std;
int a[200005], pw2[35];
string p[200005];
bool cmp(string s1, string s2){
    if(s1.size() != s2.size()) return s1.size() > s2.size();
    return s1 > s2;
}
bool cmp2(string s1, string s2){
    if(s1.size() != s2.size()) return s1.size() < s2.size();
    return s1 < s2;
}
void work(int x, int j){
    int xx = x, vis = 0;
    for(int i = 30; i >= 0; i--){
        if(xx < pw2[i] && vis) p[j] += '0';
        if(xx >= pw2[i]){
            p[j] += '1';
            xx -= pw2[i];
            if(vis == 0) vis = 1;
        }
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    pw2[0] = 1;
    for(int i = 1; i <= 30; i++){
        pw2[i] = pw2[i - 1] * 2;
    }
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        work(a[i], i);
    }
    int num[200005];
    sort(p + 1, p + 1 + n, cmp);
    for(int i = 2; i <= n; i++){
        num[i] = p[1].size() - p[i].size();
    }
    sort(p + 2, p + 2 + n, cmp2);
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= num[i]; j++){
            p[i] = '0' + p[i];
        }
    }
    for(int i = 2; i <= m; i++){
        for(int j = 0; j < p[1].size(); j++){
            int a1 = p[1][j] - '0';
            int a2 = p[i][j] - '0';
            a1 &= a2;
            p[1][j] = a1;
        }
    }
    int ans;
    for(int i = 0; i < p[1].size(); i++){
        ans += p[1][i] * pw2[p[1].size() - i - 1];
    }
    cout << ans;
}
