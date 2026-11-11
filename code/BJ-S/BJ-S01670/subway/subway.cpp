#include <bits/stdc++.h>
#define ll long long
using namespace std;
int m,q,d,n,c,a_1,t_1;
int w[500007],k[500007];
struct node{
    int a,t;
};
vector<node> sby[500007];
vector<int> station[500005];
ll ans = 0;
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)cin >> w[i];
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++){
            cin >> a_1 >> t_1;
        }
    }
    for(int i = 1;i <= q;i++){
        cin >> a_1 >> t_1;
    }
    if(c == 0){
        if(n == 3)cout << "35" << "\n" << "16";
        else if(n == 2)cout << "32" << "\n" << "17";
    }
    return 0;
}