#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,k;
vector<int> dq[100010];
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            //dq[x].push_back(y);
            //dq[y].push_back(x);
        }
        cout<<k-1<<'\n';
    }
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
