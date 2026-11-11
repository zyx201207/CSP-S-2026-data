#include<bits/stdc++.h>
using namespace std;
long long  a[10005];
int ans[10005];
bool as[10005];
int main(){
    freopen("card.int","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    queue<long long> qu;
    long long n,m,q;
    cin>>n>>m;
    while(n--){
        for(int j=1;j<=n;j++){
            cin>>q;
            if(as[q]==1){
                while(!qu.empty()) qu.pop();
            }else {
                as[q]=1;
            }
            qu.push(q);
        }
        while(!qu.empty()){
            q=qu.back();
            ans[q]++;
            qu.pop();
        }
    }
    for(int i=1;i<=m;i++){
        if(ans[i]!=0) cout<<ans[i];
    }
    return 0;
}
