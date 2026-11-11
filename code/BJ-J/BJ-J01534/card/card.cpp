#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
typedef long long ll;
int a[500005], n, m;
ll cnt[500005];
bool vis[500005];
stack<int> st;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        memset(vis, false, sizeof(vis));
        for(int j = i; j <= n; j++){
            if(vis[a[j]] && !st.empty()){
                while(st.top() != a[j]) {
                    vis[st.top()] = false;
                    st.pop();
                }
                st.pop();
            }

            st.push(a[j]);
            vis[a[j]] = true;
        }
        while(!st.empty()){
            cnt[st.top()]++;
            st.pop();
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout << cnt[i] << ' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
