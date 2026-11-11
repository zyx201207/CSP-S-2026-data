#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
stack<int> s;
int n,m,a[N],lst[M];
int cnt[M];
bool _;
signed main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    _=true;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]<a[i-1]) _=false;
    }
    if(_==true) {
        for(int i=1;i<=n;i++) {
            if(lst[a[i]]==0) {
                lst[a[i]]=i;
                s.push(a[i]);
            }
            else {
                lst[a[i]]=i;
                while(s.top()!=a[i]) s.pop();
                s.pop();
                s.push(a[i]);
            }
        }
        while(s.size()) {
            cnt[s.top()]++;
            s.pop();
        }
        for(int i=1;i<=m;i++) cnt[i]+=lst[i]-1;
        for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++) {
        memset(lst,0,sizeof(lst));
        for(int j=i;j<=n;j++) {
            if(lst[a[j]]==0) {
                lst[a[j]]=j;
                s.push(a[j]);
            }
            else {
                lst[a[j]]=j;
                while(s.top()!=a[j]) {
                    lst[s.top()]=0;
                    s.pop();
                }
                s.pop();
                s.push(a[j]);
            }
        }
        while(s.size()) {
            cnt[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
