#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    stack<int> st;
    int n, m;
    cin >> n >> m;
    int num[500005];
    for(int i=1;i<=n;i++){
        cin >> num[i];
    }
    bool a[300005] = {};
    int b[300005] = {};
    int x = 0;
    while(x<=n){
        memset(a, 0, sizeof(a));
        x++;
        for(int i=x;i<=n;i++){
            if(a[num[i]]==0){
                a[num[i]] = 1;
                st.push(num[i]);
            }
            else{
                while(st.top()!=num[i]){
                    a[st.top()] = 0;
                    st.pop();
                }
            }
            for(int i=1;i<=m;i++){
                if(a[i])
                    b[i]++;
            }
        }
        while(st.empty()!=1){
            st.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout << b[i] << ' ';
    }
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}