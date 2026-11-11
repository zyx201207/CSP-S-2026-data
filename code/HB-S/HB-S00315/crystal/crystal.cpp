#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500009] = {};
bool ch(int x){
    int w = m;
    for(int i = x;i <= n;i++){
        bool fl = 1;
        for(int j = i;j >= i - x + 1;j--){
			w -= a[i];
			w += a[j];
            if(w < 0){
                fl = 0;
                break;
            }
        }
        if(fl){
            return 1;
        }
    }
    return 0;
};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    bool fl= 1;
    int c = a[2] - a[1];
    for(int i = 2;i < n;i++){
        if(a[i+1] - a[i] != c){
            fl = 0;
        }
    }
    if(fl){
        cout << m / c + 1;
        return 0;
    }
    sort(a+1,a+n+1);
    long long l = 1,r = m,mi;
    while(l < r){
        mi = l + (r -l)/2;
        //cout << ch(mi) << endl;
        if(ch(mi)){
            l = mi + 1;
        }
        else{
            r = mi -1;
        }
    }
    cout << l - 1;
    return 0;
}
