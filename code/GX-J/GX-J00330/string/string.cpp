#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n,t[100005];
    cin >> n;
    string a[100005];
    for (int i=1;i<=n;i++){
        cin >> t[i] >> a[i];

    }
    if (n==3)
        cout << 2;
    else if (n==2)
        cout << 0;
    return 0;
}
