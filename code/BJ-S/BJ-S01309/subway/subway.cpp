#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, long long> pill;
const ll MAXM=2e5+5, MAXN=500;
ll di[MAXM], n, m, c, d, q;
ll w[MAXN];
priority_queue<pill, vector<pill>, greater<pill>> pri;
bool vis[MAXM];
pill father[MAXM];//来这里的地铁编号
int que(int s, int e, vector<vector<pair<int, long long>>> &a, vector<vector<pill>> &b){
        //printf("12323123WEWE4\n");
    memset(di, 0x3f, sizeof(di));
    memset(vis, 0x00, sizeof(vis));
    memset(father, 0x00, sizeof(father));
    
    while(!pri.empty())pri.pop();
    di[s]=0;
    pri.push({s, di[s]});
    for(int _=0;_<m;_++){
        auto dan=pri.top();
        while(vis[dan.first]){
            pri.pop();
            dan=pri.top();
        }pri.pop();
        //printf("123231234\n");
        if(dan.first==e){
            //cout << father[e].first<< ' ';
            return di[e]+w[e]+w[s]+father[e].second;
        }
        vis[dan.first]=true;
        //cout << dan.first <<'\n';
        int fa=father[dan.first].first;
        ll base=father[dan.first].second;
        for(auto &i:a[dan.first]){
            for(auto &j:b[i.first]){
                if(vis[j.first])continue;
                if(i.first==fa){
                    if(di[dan.first]<di[j.first]){
                        father[j.first]={i.first, j.second};
                        di[j.first]=di[dan.first];
                    }
                }else if(di[dan.first]+base+i.second<di[j.first]){
                        father[j.first]={i.first, j.second};
                        di[j.first]=di[dan.first]+base+i.second;
                    }
                pri.push({j.first, di[j.first]});
            }
        }
    }return -1;
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
    vector<vector<pill>> a(m+5);//站-》车
    vector<vector<pill>> b(n+5);//车-》站
    for(int i=1;i<=m;i++){
        scanf("%lld", &w[i]);
        //cout << w[i] << '\n';
    }
    for(int i=1;i<=n;i++){
        int k;scanf("%d", &k);
        for(int j=1;j<=k;j++){
            ll ai, ti;
            scanf("%lld %lld", &ai, &ti);
            a[ai].push_back({i, ti});
            b[i].push_back({ai,ti});
        }
    }
    //cout << q << " 122221111 ";
    while(q--){
    //cout << q << " 11111111 ";
        int s=0, e;
        scanf("%d %d", &s, &e);
        //cin >> s >> e;
        //cout << s << " 11111111 " <<endl;
        //que(s, e, a, b);
        printf("%d\n", que(s, e, a, b));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}