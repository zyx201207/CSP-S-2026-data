#include <bits/stdc++.h>
using namespace std;
int n,m,f=1;
int a[500005],b[300005],ans[300005];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]<a[i-1]) f=0;
    }
    if(f){
        int cnt=0;
        for(int i=1;i<=n;i++){
            cnt++;
            if(i==n || a[i]!=a[i+1]) cout << cnt << ' ';
        }
        return 0;
    }
    for(int x=1;x<=n;x++){
        memset(b,0,sizeof(b));
        for(int i=x;i<=n;i++){
            b[a[i]]++;
            if(b[a[i]]>=2){
                b[a[i]]=1;
                while(st.top()!=a[i]) st.pop();
            }
            else st.push(a[i]);
        }
        while(!st.empty()){
            ans[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++) cout << ans[i] << ' ';
    return 0;
}
