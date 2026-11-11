#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005],visit[200005];
ll ans[200005],anss[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < n;i++){
        int u = 0;
        for(int i = 1;i <= m;i++)visit[i] = -1;
        for(int j = i;j < n;j++){
            if(visit[a[j]] == -1)visit[a[j]] = i,ans[u++] = a[j];
            else{
                for(int k = visit[a[j]];k <= u;k++){
                    ans[k] = 0;
                }
                ans[u++] = a[j];
            }
        }
        for(int i = 0;i < u;i++){
            anss[ans[i]]++;
        }
    }
    for(int i = 1;i <= m;i++)cout << anss[i] << " ";
    return 0;
}
