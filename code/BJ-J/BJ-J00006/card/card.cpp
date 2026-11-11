#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9,M = 3e5 + 9;
int a[N];
bool have[M];
int sum[M];
int more[N];
int n,m;
void play(int x){
    stack<int> st;
    for(int i = x;i <= n;i++){
        if(have[a[i]]){
            while(!st.empty()){
                if(st.top() == a[i]){
                    break;
                }
                have[st.top()] = 0;
                st.pop();
            }
        }
        else {
            st.push(a[i]);
            have[a[i]] = 1;
        }

    }
    for(int i = 1;i <= m;i++) sum[i] += have[i] * more[x],have[i] = 0;
    return;
}
void solved(){

    cin >> n >> m;
    for(int i = 1;i <= n;i++) more[i] = 1;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i] == a[i - 1]){
            more[i - 1]++;
            i--,n--;
        }
    }
    for(int i = 1;i <= n;i++) play(i);
    for(int i = 1;i <= m;i++) cout << sum[i] << " ";
    return;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int t = 1;
    //cin >> t;
    while(t--) solved();
    return 0;
}
