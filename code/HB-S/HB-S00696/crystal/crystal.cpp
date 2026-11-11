#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=500005;
int n,m,a[MAXN],q[MAXN],answ=1; 
int query(int l,int r) {
    return q[r]-q[l-1];
} bool check(int l,int r) {
    int sum=query(l,r);
    return a[r]*(r-l+1)-sum<=m;
}
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m; for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);  for (int i=1;i<=n;i++) q[i]=q[i-1]+a[i];
    for (int i=2;i<=n;i++) {
        int leftt=1,rightt=i-1; 
        while (leftt<=rightt) {
            int midd=(leftt+rightt)/2;
            if (check(midd,i)) {
                rightt=midd-1;
            } else {
                leftt=midd+1;
            }
        }
        answ=max(answ,i-leftt+1);
    } cout<<answ;
    return 0;
}
/*
g++ crystal.cpp -o crystal
*/