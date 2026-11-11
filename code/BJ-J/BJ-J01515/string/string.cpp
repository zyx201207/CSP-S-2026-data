#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<int> a(n,0);
    for (int i = 0;i < n;++i){
        cin >> a[i];
    }
    if (m == 1){
        int max = 0;
        for (int i = 0;i < n;++i){
            max = max < a[i] ? a[i] : max;
        }
        cout << max;
    }
    if (m == n){
        int sum = a[0];
        for (int i = 1;i < n;++i){
            sum &= a[i];
        }
        cout << sum;
    }
    if (m == 2){
        int sum = 0;
        for (int i = 0;i < n-1;++i){
            for (int j = i+1;j < n;++j){
                int tmp = a[i]&a[j];
                sum = tmp > sum?tmp : sum;
            }
        }
        cout << sum;
    }
    return 0;
}
