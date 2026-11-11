#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
typedef long long ll;

int n, m;
struct Num{
    ll x; int d;
    string s;
}a[N];

bool cmp(Num p, Num q){
    return p.d > q.d;
}

string turn(ll x){
    string s = "";
    while(x){
        char y = x % 2 + '0';
        s += y, x /= 2;
    }
    return s;
}

void delet(int id){
    for(int i=1; i<=n; i++)
        if((int)a[i].s.size() < id || a[i].s[id] != '1')
            a[i].s = "";
    return;
}

string yes[N]; int cnt;
void collect(){
    for(int i=1; i<=n; i++)
        if(!a[i].s.empty())
            yes[++cnt] = a[i].s;
}

ll turn_back(string s){
    ll x = 0;
    for(int i=0; i<(int)s.size(); i++)
        x += (s[i]-'0') << i;
    return x;
}
ll dig[N];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    ll maxi = -1;
    for(int i=1; i<=n; i++){
        cin >> a[i].x;
        a[i].s = turn(a[i].x);
        a[i].d = a[i].s.size();
    }

    sort(a + 1, a + n + 1, cmp);
    int high = a[m].d;

    for(int k=high; k>=1; k--){
        int id = k - 1, sum = 0;
        for(int i=1; i<=n; i++)
            if((int)a[i].s.size() > id && a[i].s[id] == '1')
                sum++;
        if(sum >= m) delet(id);
    }

    collect();

    for(int i=1; i<=cnt; i++)
        dig[i] = turn_back(yes[i]);

    ll ans = dig[1];
    for(int i=1; i<=m; i++)
        ans &= dig[i];
    cout << ans;

    return 0;
}
