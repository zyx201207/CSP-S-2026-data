#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
stack<int> sta;

int d[300005]={0};
int ans[300005];
int a[N];
int n,m;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){

        for(int j=i;j<=n;j++){
            if(d[a[j]]<=0){
                sta.push(a[j]);
                d[a[j]]++;
            }
            else{
                int p=j;
                while(sta.top()!=a[j]){
                    p--;
                    d[sta.top()]--;
                    sta.pop();
                }
                sta.push(a[j]);
            }

        }

        while(!sta.empty()){
            ans[sta.top()]++;
            sta.pop();
        }

        memset(d,0,N);

    }

    for(int i=1;i<=m;i++){
        cout<<ans[i]<<"\n";
    }

    return 0;
}
