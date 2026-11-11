#include<bits/stdc++.h>
using namespace std;

int n;
long long ans;
struct link{
    int tmp;
    char c;
};
vector<link> a, b;
stack<link> st;

long long prefix[200002];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    a.push_back({0, '\0'});
    b.push_back({0, '\0'});
    for(int i = 1;i <= n;i++){
        int tmp;
        char c;
        cin >> tmp >> c;
        a.push_back({tmp, c});
        prefix[i] = prefix[i-1] + a[i].tmp;
        st.push({tmp, c});
    }
    while(!st.empty()){
        link k = st.top();
        st.pop();
        b.push_back(k);
    }
    long long len = prefix[n];
    if(len % 2 == 1) len = (len + 1) / 2;
    else len /= 2;
    int middle = -1;
    for(int i = 1;i <= n;i++){
        if(prefix[i] >= len){
            middle = i;
            break;
        }
    }
    long long leni = a[1].tmp, lenj = b[1].tmp;
    for(int i = 1, j = 1;i <= middle && j <= middle;){
        if(a[i].c == b[i].c){
            if(leni > lenj){
                j++;
                lenj += b[j].tmp;
            }
            else if(leni < lenj){
                i++;
                leni += a[i].tmp;
            }
            else{
                i++;
                j++;
                leni += a[i].tmp;
                lenj += b[j].tmp;
            }
        }
        else{
            if(leni > lenj){
                ans += b[j].tmp;
                j++;
                lenj += b[j].tmp;
            }
            else if(leni < lenj){
                ans += (b[j].tmp - lenj + leni);
                i++;
                leni += a[i].tmp;
            }
            else{
                ans += b[j].tmp;
                i++;
                j++;
                leni += a[i].tmp;
                lenj += b[j].tmp;
            }
        }
    }
    cout << ans;
    return 0;
}