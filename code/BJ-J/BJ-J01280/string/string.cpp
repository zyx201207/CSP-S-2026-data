#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    int n,t;
    int r = 0;
    char c;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> t >> c;
        s += string(t,c);
    }
    for(int i = 0,j = s.size() - 1;i < j;i++,j--){
        if(s[i] != s[j]){
            r++;
        }
    }
    cout << r << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
