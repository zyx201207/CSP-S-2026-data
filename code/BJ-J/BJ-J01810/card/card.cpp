#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
long long ans[100001] = {0};
stack<int> l;
map<int , int> mp;
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    int n , q; 
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        while(!l.empty()) l.pop();
        mp.clear();
        for(int j = i; j <= n; j++){
            mp[a[j]]++;
            l.push(a[j]);
            if(mp[a[j]] == 2){
                l.pop();
                while(l.top() != a[j]){
                    mp[l.top()]--;
                    l.pop();
                }
                mp[a[j]] = 1;
            }
        }
        for(int j = 1; j <= q; j++){
            if(mp[j] == 1) ans[j]++;
        }
    }
    for(int i = 1; i <= q; i++){
        cout << ans[i] <<" ";
    }
    fclose(stdin);
    fclose(stdout);
}