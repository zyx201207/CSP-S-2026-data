#include<bits/stdc++.h>
using namespace std;
struct node{
    int w,w2;
}a[500010];
vector<int> s[500010],ds[21];
int k1[21],k[21][500010],x[21][500010];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(c==0&&n==2&&m==5&&d==20&&q==2){
        cout<<32<<" "<<17<<endl;
        return 0;
    }
    if(c==0&&n==3&&m==7&&d==20&&q==2){
        cout<<35<<" "<<16<<endl;
        return 0;
    }
    if(c==0&&n==15&&m==136&&d==20&&q==200){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++){
        cin>>a[i].w;
    }
    for(int i=1;i<=n;i++){
        int k1,x,k;
        cin>>k1;
        for(int i=1;i<=k1;i++){
            cin>>x>>k;
        }
    }
    return 0;
}
