#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,qs;
int bfs(int st,int en , vector<int >a[] , vector<int >aa[] , map<pair<int ,int > ,int >t);
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> c >> n >> m >> d >> qs;
    vector<int >w(m+3);
    for(int i=0 ; i<m ; ++i) cin >> w[i];
    vector<int >k(n+3);
    vector<int >a[m+3];//站
    vector<int >aa[m+3];//线
    //vector<int >t[n+3];
    map<pair<int ,int > ,int >t;
    for(int i=0 ; i<n ; ++i)
    {
        cin >> k[i];
        for(int j=0 ; j<k[i] ; ++j)
        {
            int ta,tt;
            cin >> ta >> tt;
            a[ta].push_back(i);
            aa[i].push_back(ta);
            t[{ta,i}] = tt;
        }
    }
    vector<pair<int ,int > >r(qs+3);
    for(int i=0 ; i<qs ; i++) cin >> r[i].first >> r[i].second;
    //cout << '!' ;
    //if(c>=12 && c<=19)
    //{
        //int val=t[{0,0}];
        for(int i=0 ; i<qs ; i++)
        {
            int ans = w[r[i].first] + w[r[i].second] + bfs(r[i].first , r[i].second , a , aa , t);
            cout << ans << '\n';
        }
    //}

    cout << endl;
    return 0;
}
int bfs(int st,int en , vector<int >a[] , vector<int >aa[] ,map<pair<int ,int > ,int >t)
{
    queue<pair<int ,int > >q;
    for(auto i:a[st]) q.push({st , t[{st,i}]});
    bool vis[m];
    memset(vis,false,sizeof(vis));
    vis[st]=true;
    int asn=LONG_MAX;

    while(q.empty()==0)
    {
        auto tmp=q.front();
        q.pop();

        for(auto i:a[tmp.first])
        {
            for(auto j:aa[i])
            {
                tmp.second += t[{j,i}];
                if(j==en)
                {
                    asn = min(asn , tmp.second);
                    break;
                }
                if(vis[j]==false)
                {
                    vis[j]=true;
                    if(a[j].size()>1)
                    {
                        for(auto ii:a[j]) q.push({ j , tmp.second+t[{j,ii}] });
                    }
                }
            }

        }
    }
    return asn;
}
