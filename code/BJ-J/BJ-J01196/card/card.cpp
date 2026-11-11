#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int a[N],n,m,vis[N],ans[N],A;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] < a[i-1]) A = 1;
    }
    if(A == 0){
        for(int i = 1;i <= n;i++)
            if(a[i] != a[i+1]) cout << i << " ";
        cout << endl;
    }
    else{
        for(int i = 1;i <= n;i++){
            for(int o = 1;o <= m;o++) vis[o] = 0;
            stack <int> st;
            for(int j = i;j <= n;j++){
                if(vis[a[j]] == 0){
                    vis[a[j]] = 1;
                    st.push(a[j]);
                }
                else{
                    while(st.size() && st.top() != a[j]){
                        vis[st.top()] = 0;
                        st.pop();
                    }
                }
            }
            while(st.size()){
                ans[st.top()]++;
                //cout << st.top() << ' ';
                st.pop();
            }
            //cout << endl;
        }
        for(int i = 1;i <= m;i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
