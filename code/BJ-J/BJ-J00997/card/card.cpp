#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int t[M];
int ans[M];
stack<int> st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int T=1;T<=n;T++){
        memset(t,0,sizeof(t));
        for(int i=T;i<=n;i++){
            if(t[a[i]]){
                while(st.top()!=a[i]){
                    int x=st.top();
                    st.pop();
                    t[x]--;
                }
                continue;
            }
            t[a[i]]++;
            st.push(a[i]);
        }
        for(int i=1;i<=m;i++){
            if(t[i]){
                ans[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
