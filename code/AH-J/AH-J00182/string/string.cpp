#include <bits/stdc++.h>
using namespace std;
#define int long long;
signed main (){
    int n;
    cin>>n;
    string s = "";
    for(int i = 1;i <= n;i++){
        int x;
        cin>>x;
        string t;
        cin>>t;
        while(x--)s+=t;
    }

    return 0;
}
