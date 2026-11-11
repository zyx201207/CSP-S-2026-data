#include<bits/stdc++.h>
using namespace std;
int tmpa[1000005],tmpp[1000005];
inline int solve(int n,int lim){
    if(n <= 0){
        return 0;
    }
    for(int i = 1;i <= n;i++){
        tmpp[i] = 0;
        //cout << tmpa[i] << " ";
    }
    int ans = 1e9;
    //cout << n << '\n';
    for(int i = 1;i <= n;i++){
        int tmpr = min(i + lim - tmpa[i],n + 1);
        tmpp[tmpr] = max(tmpp[tmpr],i - lim + tmpa[i]);
        //cout << i - lim + tmpa[i] << " " << tmpr << '\n';
    }
    int nowr = 0;
    for(int i = 0;i <= n;i++){
        while(nowr < n && i >= tmpp[nowr + 1]){
            nowr++;
        }
        ans = min(ans,n - nowr + i);
    }
    //cout << ans << '\n';
    return ans;
}
int c,t,n,k,dep[1000005],dfn[1000005],ed[1000005],cnt,f[1000005],siz[1000005];
int flag[1000005],flag2[1000005],d[1000005],flag3[1000005];
vector<int> b[1000005];
int tmp[1000005],cnt2;
int lim;
inline void dfss(int x,int fa){
    siz[x] = 1;
    flag[x] = 0;
    if(dep[x] == lim){
        tmp[++cnt2] = x;
    }
    flag3[x] = 0;
    for(int i : b[x]){
        if(i != fa && dep[i] < lim){
            flag[x] = max(flag[x],dep[i] + 1);
        }else if(i != fa){
            flag3[x]++;
            dfss(i,x);
            siz[x] += siz[i];
        }
    }
}
inline void dfs2(int x,int fa){
    flag2[x] = flag[x];
    if(fa){
        flag2[x] = max(flag2[x],flag2[fa] + 1);
    }
    for(int i : b[x]){
        if(i != fa && dep[i] >= lim){
            dfs2(i,x);
        }
    }
}
inline int lca(int x,int y){
    while(dfn[x] > dfn[y] || ed[x] < dfn[y]){
        x = f[x];
    }
    return x;
}
int lim2[1000005],mina,tmpi;
inline void dfs3(int x,int fa,int op,int nowi){
    //cout << x << '\n';
    nowi = max(nowi,lim2[d[x]]);
    //cout << d[x] << " " << nowi << " " << -d[x] + siz[tmpi] + nowi + op << '\n';
    mina = min(mina,-d[x] + siz[tmpi] + nowi + op);
    int lst;
    if(d[x] + lim - flag[x] + 1 >= 1){
        lst = lim2[d[x] + lim - flag[x] + 1];
        lim2[d[x] + lim - flag[x] + 1] = max(lim2[d[x] + lim - flag[x] + 1],d[x] - lim + flag[x] + 1);
    }
    //cout << d[x] + lim - flag[x] + 1 << " " << d[x] - lim + flag[x] + 1 << '\n';
    for(int i : b[x]){
        if(dep[i] >= lim && i != fa){
            dfs3(i,x,op,(flag3[x] >= 2 ? d[x] : nowi));
        }
    }
    if(d[x] + lim - flag[x] + 1 >= 1){
        lim2[d[x] + lim - flag[x] + 1] = lst;
    }
}
inline int check(){
    if(dep[1] <= lim){
        return 1;
    }
    if(!lim){
        return n <= k;
    }
    cnt2 = 0;
    dfss(1,0);
    dfs2(1,0);
    tmpi = lca(tmp[1],tmp[cnt2]);
    int flag1 = 0;
    for(int i : b[tmpi]){
        if(i == f[tmpi]){
            continue;
        }
        if(dep[i] >= lim){
            if(!flag1){
                flag1 = i;
            }
        }
    }
    //cout << cnt2 << " " <<'\n';
    if(flag3[tmpi] == 2 && flag2[tmpi] < lim){
        int i = 1;
        while(dfn[tmp[i + 1]] <= ed[flag1]){
            i++;
        }
        int tmpn = 0;
        int t1 = lca(tmp[1],tmp[i]);
        int t2 = lca(tmp[i + 1],tmp[cnt2]),sizz = siz[t1] + siz[t2];
        //cout << i << " " << t1 << " " << t2 << '\n';
        while(t1 = f[t1]){
            if(t1 == tmpi){
                break;
            }
            tmpa[++tmpn] = flag[t1];
        }
        tmpa[++tmpn] = flag2[tmpi];
        int t3 = t2,tmpn2 = tmpn;
        while(t3 = f[t3]){
            if(t3 == tmpi){
                break;
            }
            tmpn2++;
        }
        tmpn = tmpn2;
        while(t2 = f[t2]){
            if(t2 == tmpi){
                break;
            }
            tmpa[tmpn2--] = flag[t2];
        }
        if(solve(tmpn,lim) + sizz <= k){
            //    cout << "?";
            return 1;
        }
    }
    int tmpn = 0;
    for(int i = f[tmpi];i;i = f[i]){
        if(flag2[i] <= lim){
            break;
        }
        //cout << flag[i] << " ";
        tmpa[++tmpn] = flag[i];
    }
    if(solve(tmpn,lim) + 1 + siz[tmpi] <= k){
        return 1;
    }
    int cntt = 0;
    int x = tmpi;
    while(flag2[f[x]] >= lim){
        x = f[x];
        cntt++;
    }
    for(int i = 1; i <= n;i++){
        lim2[i] = 0;
    }
    mina = 1e9;
    //cout << siz[tmpi] << '\n';
    dfs3(tmpi,f[tmpi],cntt,d[tmpi]);
    //cout << mina << '\n';
    return mina <= k;
}
inline void dfs(int x,int fa){
    f[x] = fa;
    dep[x] = 0;
    dfn[x] = ++cnt;
    d[x] = d[fa] + 1;
    for(int i : b[x]){
        if(i != fa){
            dfs(i,x);
            dep[x] = max(dep[x],dep[i] + 1);
        }
    }
    ed[x] = cnt;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1;i < n;i++){
            int u,v;
            cin >> u >> v;
            b[u].push_back(v);
            b[v].push_back(u);
        }
        cnt = 0;
        dfs(1,0);
        int l = 0,r = n / 2;
        while(l < r){
            int mid = (l + r) / 2;
            lim = mid;
            if(check()){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        cout << l << '\n';
        for(int i = 1;i <= n;i++){
            b[i].clear();
        }
    }
    return 0;
}
