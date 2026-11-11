#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;
long long st[500005],own[500005];
struct way{
    long long to,need;
};
vector<way> a[500005];
long long dist[500005];
bool v[500005];
int main ()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> st[i];
    for(int i = 1;i <= n;i++){
        long long num;
        cin >> num;
        int sub[num],sta[num];
        for (int j = 0;j < num;j++) cin >> sta[j] >> sub[j];
        for (int j = 0;j < num;j++){
            for (int k = 0;k<num;k++)
                if (j!=k){
                    a[sta[j]].push_back({sta[k],sub[k]});
                }else{
                    own[j] = sub[j];
                }
        }
    }
    for (int i = 1;i <= q;i ++){
        long long start,endst;
        cin >> start >> endst;
        for (int k = 0;k <= m;k++){
            dist[k] = INF;
            v[k] = 0;
        }
        dist[start] = 0;
        for (int c=1;c<=n;c++){
            int t = -1;
            for (int b=1;b<=n;b++){
                if (!v[b] &&(t==-1 || dist[t] > dist[b])) t = b;
            }
            if (t == -1 || dist[t] == INF) break;
            for (const way &Way:a[t]){
                dist[Way.to] = min(dist[Way.to],dist[t] + Way.need + own[t]);
            }
        }
        cout << dist[endst] + own[start] + st[start] + st[endst] << endl;
    }
    return 0;
}
