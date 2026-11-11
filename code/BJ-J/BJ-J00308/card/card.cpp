#include <bits/stdc++.h>
using namespace std;
deque<int> dq;
int n,m;
int a[500005],h[300005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >>n>>m;
    for (int i=1;i<=n;i++){
        cin >>a[i];
    }
    int cnt=0,T=n;
    while (T--){
        cnt++;
        for (int i=cnt;i<=n;i++){
            h[a[i]]++;
            if (h[a[i]]>1){
                while (!dq.empty()&&dq.back()!=a[i]) {
                    h[dq.back()]--;
                    dq.pop_back();
                }
            }
            else dq.push_back(a[i]);
        }
        memset(h,0,sizeof(h));
        while (!dq.empty()){
            ans[dq.back()]++;
            dq.pop_back();
        }
    }
    for (int i=1;i<=m;i++) cout <<ans[i]<<' ';
    return 0;
}
