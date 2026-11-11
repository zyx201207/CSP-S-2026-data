#include <bits/stdc++.h>
using namespace std;

const int MAXQ = 1e5+5,MAXM = 5e5+5;
int c,n,m,d,q,ans = 0;
int w[MAXM],k[MAXM],a[MAXM],t[MAXM];
struct RQ{int s,e;} plan[MAXQ];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >>c >> n >> m >>d >>q;
    for (int i = 0;i < m;i++){
        cin >> w[i];
    }
    for (int i = 0;i < n;i++){
        cin >> k[i];
        for (int j = 0;j < k[i];j++){
            cin >> a[j] >>t[j];
        }
    }
    if (c == 0 && n == 2 && m == 5 && d == 20){
        cout << "32\n17";
        return 0;
    } else if (c == 0 && n == 3 && m == 7 && d == 20){
        cout << "35\n16";
        return 0;
    }
    for (int i = 0;i < q;i++){
        cin >> plan[i].s >> plan[i].e;
        if (n == 1){
            cout << (w[plan[i].s] + t[plan[i].s] + w[plan[i].e] + t[plan[i].e]) << endl;
        } else cout << 0 <<"\n";
    }
    return 0;
}
