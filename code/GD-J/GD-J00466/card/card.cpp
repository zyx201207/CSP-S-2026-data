#include<bits/stdc++.h>
using namespace std;
//maxn:500000 maxm:300000;
int n,m;
int cnt[300005];
int a;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    while(n--){
        cin>>a;
        cnt[a]++;
    }
    for(int i=1;i<=m;i++){
        cout<<(cnt[i]+=cnt[i-1])<<' ';
    }

    return 0;

}
