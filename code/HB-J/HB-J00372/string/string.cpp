#include<bits/stdc++.h>
using namespace std;

struct T{
    int sz;
    char ch;
}a[200009];

bool f(string t){
    string t1 = t;
    reverse(t1.begin(),t1.end());
    if(t1 == t) return 1;
    return 0;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    string s;
    long long l = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i].sz >> a[i].ch;
        l += a[i].sz; 
        s  = s + string(a[i].sz,a[i].ch);
    }

    if(n == 1){
        cout << 0;
        return 0;
    }
    
    else if(f(s)){
        cout << 0;
        return 0;
    }

    else{


        long long ans = 0;
        if(l % 2 == 0){
            ans = l / 2;
            for(int i = 0;i < l / 2;i++){
                if(s[i] == s[l -1 - i]) ans--;
            }
        }
        else{
            ans = (l - 1) / 2;
            for(int i = 0;i < (l - 1) / 2;i++){
                if(s[i] == s[l -1 - i]) ans--;
            }
        }
        cout << ans;


    }
    return 0;
}
