#include<bits/stdc++.h>
using namespace std;
int a[100009],ans[100009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < n;j++){
            cin >> a[j];
        }
        string s = "";
        for(int j = n - i + 1;j <= n;j++){
            int l = s.size();
            auto t = s.find(char(j + '0'));
            if(t != s.size()){
                s = s.substr(t,l);
                s + to_string((j + '0'));
            }
            else s + to_string((j + '0'));
        }
        for(int j = 1;j <= m;j++){
            if(s.find(char(j + '0')) != s.size()){
                ans[j] ++;
            } 
        }
    }
    for(int j = 1;j <= m;j++){
        cout << ans[j] << " ";
    }
    return 0;
}
