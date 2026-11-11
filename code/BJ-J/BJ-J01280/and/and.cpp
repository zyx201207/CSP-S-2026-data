#include<bits/stdc++.h>
using namespace std;

int a[200005] = {0};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m,r = -2147483648;
    cin >> n >> m;
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    if(m != 2) {
        cout << 0;
        goto X;
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j) continue;
            r = max(r,a[i] & a[j]);
        }
    }
    cout << r << endl;
X:
    fclose(stdin);
    fclose(stdout);
    return 0;
}
