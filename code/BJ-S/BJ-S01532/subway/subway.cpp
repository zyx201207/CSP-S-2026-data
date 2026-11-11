#include<bits/stdc++.h>
using namespace std;
struct Node{
    vector<long long> line,t;
    int len;
}a1[500009];
long long c,n,m,d,q,x,y,station[500009],ans=0x3f3f3f3f;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>station[i];
    }
    for(int i=1;i<=n;i++){
        int k,x1,x2;
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>x1>>x2;
            a1[x1].line.push_back(i);
            a1[x1].t.push_back(x2);
            a1[x1].len++;
        }
    }
    while(q--){
        cin>>x>>y;
        cout<<station[x]+station[y]+a1[x].t[0]+a1[y].t[0]<<endl;
    }
}
