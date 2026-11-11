#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int a[N],b[N],aaa[N],bbb[N],cnt = 0;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k;
    cin>>c>>t;
    while(t--) {
        cin>>n>>k;
        for(int i = 1;i < n;i++) {
            cin>>a[i]>>b[i];
            if(a[i] > b[i]) swap(a[i],b[i]);
        }
        for(int i = 1;i < n;i++) {
            aaa[a[i]]++;
        }
        for(int i = 1;i < n;i++) {
            bbb[b[i]]++;
        }
        for(int i = 1;i <= n;i++) bbb[i]+=aaa[i];
        for(int i = 1;i <= n;i++) {
            if(bbb[i] == 1)cnt++;
        }
        if(cnt == 2 || k == 1) cout<<2;
        else if(n == k) cout<<0;
        else cout<<1;
        cout<<"\n";
    }
    return 0;
}
