#include<bits/stdc++.h>
using namespace std;
vector<char> str;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    char c;
    int t;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> t >> c;
        for(int j = 0;j < t;j++){
            str.push_back(c);
        }
    }
    int ans = 0;
    int l = str.size();
    for(int i = 0;i < l/2;i++){
        if(str[i] != str[l-i-1]) ans++;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
