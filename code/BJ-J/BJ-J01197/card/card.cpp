#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const int M = 3e5+5;
int a[N];
int ans[M];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        stack<int> s;
        set<int> st;
        for(int j=i; j<=n; j++){
            if(!st.count(a[j])){
                st.insert(a[j]);
                s.push(a[j]);
            }
            else{
                while(s.top()!=a[j]){
                    int u = s.top();
                    s.pop();
                    st.erase(u);
                }

            }
        }
        while(s.size()){
            int u = s.top();
            s.pop();
            ans[u]++;
        }
    }
    for(int i=1; i<=m; i++)cout <<ans[i] << " ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
