#include <bits/stdc++.h>
using namespace std;

int m, n;


int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    int a[n+5];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    int l = INT_MAX;
    for(int i=0; i<m; i++)
    {
        int max_n = INT_MIN;
        int ind;
        for(int j=0; j<n; j++){
            if(max_n < (l & a[j])){
                max_n = max(int(l & a[j]), max_n);
//                cout << i << " " << max_n << endl;
                ind = j;
            }
        }
//        cout << "a" << a[ind] << "index" << ind << endl;
        l = max_n;
        a[ind] = 0;
    }
    cout << l;
    return 0;

}
