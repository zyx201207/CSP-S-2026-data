#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;
long long t,n,d,x,nw,wn,ps,sp,rs,a[2000001],pr[2000001],nt[2000001];
bool ok,vs[2000001];
vector<long long> vc,cv;
unordered_map<long long,long long> cn;
long long sv(long long m) {
    long long rt=0;
    for(long long i=1;i<=m;i++) {
        for(long long j=i+1;j<=m;j++) {
            nw=wn=ps=ok=0;
            cv.clear();
            x=vc[i-1];
            while(x<vc[j-1]) {
                cv.push_back(x);
                vs[x]=true;
                nw++;
                x=nt[x];
            }
            x=vc[j-1];
            while(x>vc[i-1]) {
                if(!vs[x]) {
                    ps=x;
                    cv.push_back(x);
                    vs[x]=true;
                }
                wn++;
                x=pr[x];
            }
            for(long long p:cv) vs[p]=false;
            if(nw!=wn || cv.size()!=nw+2) continue;
            for(long long p=0;p<cv.size();p++) {
                if(cv[p]==ps+1) {
                    ok=true;
                    break;
                }
            }
            if(!ok) continue;
            rt++;
        }
    }
    return rt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>t;
    if(t<=6) {
        cin>>t;
        while(t--) {
            rs=0;
            cin>>n>>d;
            for(long long i=1;i<=n;i++) cin>>a[i];
            for(long long i=1;i<=n;i++) {
                if(i<n) cn[a[i]]=a[i+1];
                pr[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
                nt[i]=lower_bound(a+1,a+n+1,a[i]+d+1)-a-1;
                vc.push_back(i);
                if(nt[i]<=i) {
                    rs+=sv(vc.size());
                    vc.clear();
                }
            }
            rs+=sv(vc.size());
            vc.clear();
            cout<<rs<<"\n";
        }
        return 0;
    }
    cin>>t;
    while(t--) {
        cin>>n>>d;
        for(long long i=1;i<=n;i++) cin>>a[i];
        if(n==1) {
            cout<<0<<"\n";
            continue;
        }
        d/=(a[2]-a[1]);
        if(d<=1) {
            cout<<0<<"\n";
            continue;
        }
        cout<<max(n-2*d+1,0LL)<<"\n";
    }
    return 0;
}
