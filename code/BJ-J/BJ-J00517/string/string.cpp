#include<bits/stdc++.h>
using namespace std;
struct node{
    int x, num;
    char s;
} a[200005];
int suf[200005];
string st;
long long sum, c, ans = 0;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].s;
        for(int j = 1; j <= a[i].x; j++){
            st += a[i].s;
        }
    }
    for(int i = 0; i < (int)(st.size() / 2); i++){
        if(st[i] != st[st.size() - i - 1]){
            //cout <<i <<' '<< st[i] << ' ' << st[st.size() - i] << endl;
            ans++;
        }
    }
    cout << ans << endl;
}
