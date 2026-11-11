#include<bits/stdc++.h>
#define int long long
using namespace std;
struct zfd{
    int len;
    char tp;
};
zfd a[200005];
deque<zfd>dq;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m=0;
    cin>>n;
    int lsts=0;
    char lstt=0;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        if(y!=lstt){
            a[m]={lsts,lstt};
            lstt=y;
            lsts=x;
            m++;
        }
        else lsts+=x;
    }
    a[m]={lsts,lstt};
    for(int i=1;i<=m;i++) dq.push_back(a[i]);
    int cnt=0;
    while(dq.size()>1){
        zfd ft=dq.front();
        zfd bk=dq.back();
        dq.pop_front();
        dq.pop_back();
        if(ft.tp==bk.tp){
           if(ft.len<bk.len) dq.push_back({bk.len-ft.len,bk.tp});
           if(ft.len>bk.len) dq.push_front({ft.len-bk.len,ft.tp});
        }
        else{
            if(ft.len<bk.len){
                cnt+=ft.len;
                dq.push_back({bk.len-ft.len,bk.tp});
            }
            if(ft.len==bk.len) cnt+=ft.len;
            if(ft.len>bk.len){
                cnt+=bk.len;
                dq.push_front({ft.len-bk.len,ft.tp});
            }
        }
    }
    cout<<cnt;
    return 0;
}
