#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int n, m;
int a[N];
bool flg = 1;
int ans[N];
int cnt[N];
int lst[N], lft[N];
stack<int> st;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i - 1] > a[i])flg = 0;
    }
    if(m == 1){
        cout << n;
        return 0;
    }
    if(m == 2){
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= n; i++)if(a[i] == 1)cnt1++;else cnt2++;
        if(a[n] == 1)cout << n << " " << cnt2;
        else cout << cnt1 << " " << n;
        return 0;
    }
    if(flg){
        for(int i = 1; i <= n; i++)ans[a[i]] = i;
        for(int i = 1; i <= m; i++){
            cout << ans[i] << " ";
        }
        return 0;
    }
    if(n <= 5000){
        for(int fi = 1; fi <= n; fi++){
            for(int i = 1; i <= m; i++)cnt[i] = 0;
            for(int i = fi; i <= n; i++){
                if(cnt[a[i]]){
                    while(a[st.top()] != a[i])cnt[a[st.top()]]--, st.pop();
                }else{
                    cnt[a[i]]++;
                    st.push(i);
                }
            }
            while(!st.empty()){ 
                ans[a[st.top()]]++;
                st.pop();
            }
        }
        for(int i = 1; i <= m; i++)cout << ans[i] << " ";      
        return 0 ;
    }
    for(int i = 1; i <= n; i++){
        lst[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        while(!st.empty() && lst[a[st.top()]] < lst[a[i]])st.pop();
        if(st.empty())lft[i] = 1;
        else lft[i] = st.top() + 1;
        st.push(i);
    }
    for(int i = 1; i <= n; i++){
        ans[a[i]] += (i - lft[i] + 1);
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}