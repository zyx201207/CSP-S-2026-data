#include<bits/stdc++.h>
using namespace std;

const int N=2e4+5,M=2e3+5;
int c,n,m,d,q;
int w[N];
struct node{
    int k,a[M],t[M];
}p[N];
set<int> pa[N];
map<int,int> path[N];
bool min_n[N];
struct Node{
    int x,k;
	bool operator<(const Node &p) const{
        return k>p.k;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++){
        cin >> w[i];
    }
    for (int i=1;i<=n;i++){
        cin >> p[i].k;
        for (int j=1;j<=2*p[i].k;j++){
            cin >> p[i].a[j] >> p[i].t[j];
            path[p[i].a[j-1]][p[i].a[j]]=1;
            path[p[i].a[j]][p[i].a[j-1]]=1;
            pa[p[i].a[j-1]].insert(p[i].a[j]);
            pa[p[i].a[j]].insert(p[i].a[j-1]);
        }
    }
    while (q--){
        int x,y,ans=0;
        cin >> x >> y;
        queue<Node> qu;
        qu.push({x,0});
        while (!qu.empty()){
            Node o=qu.front();
            qu.pop();
            for (auto i:pa[o.x]){
                if (i==y) {ans+=p[1].t[1]*(o.k+1)*2;break;}
                if (min_n[i]==0){
                    min_n[i]=1;
                    qu.push({i,o.k+1});
                }
            }
            if (ans!=0) break;
        }
        ans+=w[x]+w[y];
        cout << ans << '\n';
    }
	return 0;
}

