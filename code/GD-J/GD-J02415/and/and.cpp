#include <iostream>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    long long num[n];
    long long noo;
    long long ans = 0;
    for(int i = 0;i < n;++i){
        cin >> num[i];
    }
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            noo = num[i] & num[j];
            if(noo > ans) ans = noo;
        }
    }

    cout << ans;
    return 0;
}

