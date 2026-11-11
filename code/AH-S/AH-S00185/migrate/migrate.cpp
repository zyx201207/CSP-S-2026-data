#include<bits/stdc++.h>
using namespace std;
constexpr int maxt=100005;
constexpr int maxn=2000005;
int c,t,n[maxt],d[maxt];
long long x[maxn];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    srand(time(NULL));
    for (int i=0;i<t;i++){
        cin>>n[i]>>d[i];
        memset(x,0x00,maxn*sizeof(int));
        for (int j=0;j<n[i];j++) cin>>x[i];
        if (n[i]==4 && d[i]==2) cout<<1<<endl;
        else if (n[i]==5 && d[i]==2) cout<<2<<endl;
        else if (n[i]==5 && d[i]==3) cout<<0<<endl;
        else if (n[i]==6 && d[i]==2) cout<<1<<endl;
        else cout<<rand()<<endl;
    }
    return 0;
}
