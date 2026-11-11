#include<iostream>
#include<queue>
using namespace std;
long long n,m,rs,a[200001];
vector<long long> vc,cv;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) {
        vc.push_back(i);
        cin>>a[i];
    }
    for(long long i=30;i>=0;i--) {
        cv.clear();
        for(long long j:vc)
            if(a[j]&(1LL<<i))
                cv.push_back(j);
        if(cv.size()>=m) {
            rs+=(1LL<<i);
            vc=cv;
        }
    }
    cout<<rs<<"\n";
    return 0;
}
