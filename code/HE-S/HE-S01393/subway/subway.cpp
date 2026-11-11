#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef unordered_set<int> uset;

typedef vector<uset> vuset;

const int INF = 1e9;

vi w;

vii s2t; // Station To Subway
vuset t2s; //

vii s2t_table;

vii flod(503,vi(503,INF));

int main()
{
    // 苦思冥想怎么感觉这个就是 Flody
    iostream::sync_with_stdio(false);
    cout.tie(nullptr);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);


    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;

    w.resize(m+3);
    for(int i = 0;i<m;i++) cin >> w[i];
;
    s2t.resize(m+3);
    t2s.resize(n+3);

    s2t_table.resize(m+3);
    for(int i  = 0;i<=m;i++) s2t_table.resize(n+3);

    //cout << "NO!";
    for(int i = 1;i<=n;i++){
        int g;
        cin >> g;
        for(int j = 0;j < g;j++){
            long long s,t;
            cin >> s >> t;

            s2t[s].push_back(i);
            t2s[i].insert(s);

            s2t_table[s][i] = t;
        }
    }

    //cout << "NO!";


    // Fill

    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            // Fill
            auto pi = t2s[i].begin();
            auto pj = t2s[j].begin();

            while(pi!=t2s[i].end()&&pj!=t2s[j].end()){
                if(*pi == *pj && s2t_table[*pi][i] + s2t_table[*pi][j] < flod[i][j]) flod[i][j] == s2t_table[*pi][i] + s2t_table[*pi][j];

                if(*pi > *pj) pj++;
                else pi++;
            }

        }
    }

    //for(int i = 1;i<=n;i++){
     //   for(int j = i+1;j<=n;j++){
    //        cout << flod[i][j] << " ";

    //     }
    //    cout << endl;
    //}


    return 0;
}
