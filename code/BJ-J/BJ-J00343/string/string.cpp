#include<iostream>
using namespace std;
long long n,ps,rs;
pair<long long,char> a[200001];
pair<long long,long long> b[200001];
long long qr(long long lb,long long rb,char x) {
    long long rt=0;
    for(;ps>=1;ps--) {
        if(b[ps].first<rb) {
            if(a[ps].second==x) rt+=(min(b[ps].second,lb)-rb+1);
            return rt;
        }
        if(a[ps].second==x) rt+=(min(b[ps].second,lb)-b[ps].first+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++) {
        cin>>a[i].first>>a[i].second;
        b[i].first=b[i-1].second+1;
        b[i].second=b[i].first+a[i].first-1;
    }
    ps=n;
    for(long long i=1;i<=n;i++) {
        if(b[i].first>b[n].second/2) break;
        rs+=qr(b[n].second-b[i].first+1,b[n].second-min(b[i].second,b[n].second/2)+1,a[i].second);
    }
    cout<<b[n].second/2-rs<<"\n";
    return 0;
}
