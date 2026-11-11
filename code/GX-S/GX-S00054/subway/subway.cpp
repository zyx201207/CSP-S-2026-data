#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,r;
long long w[500005];
long long x[500005];
long long y[500005];

struct l{
    long long k;
    long long z[500005];
    long long t[500005];
}l[500005];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        cin >> l[i].k;
        for(int j=1;j<=l[i].k;j++){
            cin >> l[i].z[j] >> l[i].t[j];
        }
    }
    for(int i=1;i<=q;i++){
        cin >> x[i] >> y[i];
    }
    long long now=q;
    while(q--){
        long long time=0;
        long long ans=0;
        for(int i=1;i<=n;i++){
            int f=0;
            for(int j=1;j<=l[i].k;j++){
                if(l[i].z[j]==x[now-q]){
                    ans+=l[i].t[j];
                    f++;
                }
                if(l[i].z[j]==y[now-q]){
                    ans+=l[i].t[j];
                    f++;
                }
            }
            if(f==2) time=max(time,ans);
        }
        cout << time+w[x[now-q]]+w[y[now-q]] << endl;
    }
    return 0;
}
