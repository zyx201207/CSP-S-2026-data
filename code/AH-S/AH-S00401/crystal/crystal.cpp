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
    return ans*f;
}

ll n,m,p1,p2,res,lis[500005],pre[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> lis[i];

    sort(lis+1,lis+n+1);p2 = 1;
    for(int i = 1;i <= n;i++) pre[i] = pre[i-1] + lis[i];
    for(p1 = 1;p1 <= n;p1++){
        while(p2 <= p1 && (p1-p2+1)*lis[p1]-(pre[p1]-pre[p2-1]) > m) p2++;
        res = max(res,p1-p2+1);
    }
    if(res != 1) cout << res;
    else cout << 0;

    fclose(stdin);fclose(stdout);
    return 0;
}
