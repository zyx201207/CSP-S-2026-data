#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w", stdout);
    int n, m;
    int a[200010] = {};
    int Max = -0x3f3f3f3f;

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        Max = max(Max, a[i]);
    }
    cout << Max;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

