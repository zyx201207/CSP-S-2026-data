#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N];
int vis[M],add[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >>m;
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++){
        memset(vis,0x00,sizeof vis);
        for(int j = i;j <= n;j++){
            if(vis[a[j]]!=0){
                for(int k = vis[a[j]];k < j;k++)vis[a[k]]=0;

            }
            vis[a[j]]=j;
        }
        for(int j = 1;j <= m;j++){
            if(vis[j])add[j]++;
        }
    }
    for(int i = 1;i <= m;i++)cout << add[i] << " ";
    return 0;
}
