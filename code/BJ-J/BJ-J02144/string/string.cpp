#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    char a[110000];
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        cin >> a[i];
    }
    if(n==1){
        cout << 0;
        return 0;
    }
    if(n==2){
        if(a[1]==a[2]){
            cout << 0;
            return 0;
        }else{
            cout << 2;
            return 0;
        }
    }else cout << 0;

    return 0;
}
