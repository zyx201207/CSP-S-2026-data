#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans,f;char c;
inline ll read(){
    ans = 0;f = 1;char c;
    c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ans = 10*ans + c-'0';
        c = getchar();
    }
    return ans;
}

ll n,m,a,b,res,cnt1,cnt2,cnt,tmp;
vector<int> lis[1000005];
int in[1000005];queue<int> q;bool is[100005];
ll minn[1000005];

bool iss(){
    memset(is,0,sizeof(is));
    for(int i = 1;i <= n;i++){
        if(in[i] = 1){
            q.push(i);

            cnt = 1;
            while(q.size()){
                int t = q.front();q.pop();
                for(int it : lis[t]){
                    if(is[it]) continue;
                    if(in[it] != 1) continue;

                    is[it] = 1;
                    cnt++;
                    q.push(it);
                }
            }

            if(cnt != cnt1) return 0;
            break;
        }
    }

    cnt = 0;
    for(int i = 1;i <= n;i++){
        if(in[i] = 2){
            q.push(i);

            cnt = 1;
            while(q.size()){
                int t = q.front();q.pop();
                for(int it : lis[t]){
                    if(is[it]) continue;
                    if(in[it] != 2) continue;

                    is[it] = 1;
                    cnt++;
                    q.push(it);
                }
            }

            if(cnt != cnt2) return 0;
            break;
        }
    }
    return 1;
}

void dfs(int dep,int bef){
    if(dep == m+1){
        if(!iss()) return;

        memset(minn,0x3f,sizeof(minn));
        for(int i = 1;i <= n;i++){
            if(in[i]){
                minn[i] = 0;
                q.push(i);
            }
        }

        while(q.size()){
            int t = q.front();q.pop();
            for(int it : lis[t]){
                if(minn[it] > minn[t]+1){
                    minn[it] = minn[t]+1;
                    q.push(it);
                }
            }
        }

        tmp = 0;
        for(int i = 1;i <= n;i++) tmp = max(tmp,minn[i]);

        res = min(res,tmp);
        return;
    }

    for(int i = bef+1;i <= n;i++){
        in[i] = 1;cnt1++;
        dfs(dep+1,i);
        in[i] = 2;cnt1--;cnt2++;
        dfs(dep+1,i);
        in[i] = 0;cnt2--;
    }
}

void sol(){
    cin >>n >>m;
    for(int i = 1;i <= 1000000;i++) lis[i].clear();

    for(int i = 1;i < n;i++){
        cin >>a >>b;
        lis[a].push_back(b);
        lis[b].push_back(a);
    }

    res = LLONG_MAX;
    dfs(1,0);

    cout << res << endl;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    ll c,t;cin >>c >> t;
    while(t--) sol();

    fclose(stdin);fclose(stdout);
    return 0;
}
