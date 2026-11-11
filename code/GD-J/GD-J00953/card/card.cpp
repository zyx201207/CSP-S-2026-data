#include<iostream>
#include<deque>
#include<unordered_set>
using namespace std;

const int MAXN = int(2e5)+5;

int n,m;
int a[MAXN];
int ans[MAXN];
deque<int> dq;
unordered_set<int> st;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    // frepopen
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++){
        // 第i局
        dq.clear();
        st.clear();
        for(int j = i;j<=n;j++){
            if(st.find(a[j]) == st.end()){
                st.insert(a[j]);
                dq.push_back(a[j]);
            }
            else{
                while(dq.back() != a[j]){
                    st.erase(dq.back());
                    dq.pop_back();
                }
            }
        }
        for(auto ed:st){
            ans[ed]++;
        }
    }
    for(int i = 1;i<=m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}