#include <bits/stdc++.h>
#define N 300010
#define int long long
using namespace std;
char c[N];
int a[N];
vector <pair <int, char> > g2;
struct node{
    int l, r;
    char c;
};
vector <node> g1;
int low(int x){
    int l = 0, r = g1.size() - 1;
    while(l <= r){
        int mid = l + r >> 1;
        if(g1[mid].l <= x && g1[mid].r >= x){
            return mid;
        }
        if(x > g1[mid].r){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
}
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*
    int n;
    cin >> n;
    int l, r;
    char temp;
    int sum = 0;
    string s = "";
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        sum += a[i];
        for(int j = 1; j <= a[i]; j++){
            s = s + c[i];
        }
    }
    sum--;
    int answer = 0;
    for(int i = 0; i <= sum / 2; i++){
        if(s[i] != s[sum - i]){
            answer++;
        }
    }
    cout << answer << endl;
    */
    int n;
    cin >> n;
    int sum = 0, total = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        total += a[i];
    }
    if(total <= 1e8){
        string s = "";
        for(int i = 1; i <= n; i++){
            sum += a[i];
            for(int j = 1; j <= a[i]; j++){
                s = s + c[i];
            }
        }
        total--;
        int answer = 0;
        for(int i = 0; i <= total / 2; i++){
            if(s[i] != s[total - i]){
                answer++;
            }
        }
        cout << answer << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        if(sum + a[i] <= (total + 1) / 2){
            g1.push_back({sum + 1, sum + a[i], c[i]});
            sum += a[i];
        } else if(sum < (total + 1) / 2 && sum + a[i] > (total + 1) / 2){
            g1.push_back({sum + 1, (total + 1) / 2, c[i]});
            g2.push_back({a[i] - (total + 1) / 2 + sum, c[i]});
            sum += a[i];
        } else {
            g2.push_back({a[i], c[i]});
            sum += a[i];
        }
    }
    /*
    for(int i = 0; i < g1.size(); i++){
        cout << g1[i].l << ' ' << g1[i].r << endl;
    }
    cout << endl;
    for(int i = 0; i < g2.size(); i++){
        cout << g2[i].first << ' ' << g2[i].second << endl;
    }
    */
    int _sum = (total + 1) / 2 + 1;
    int answer = 0;
    for(auto i : g2){
        int r = total - _sum + 1;
        int l = r - i.first + 1;
        _sum += i.first;
        int x = low(l), y = low(r);
        if(x == y){
            if(i.second != g1[x].c){
                answer += i.first;
            }
        } else {
            if(i.second != g1[x].c){
                answer += g1[x].r - l + 1;
            }
            if(i.second != g1[y].c){
                answer += r - g1[y].l + 1;
            }
        }
        //cout << l << ' ' << r << endl;
    }
    cout << answer << endl;
}

