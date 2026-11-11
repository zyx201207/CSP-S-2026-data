#include <iostream>
using namespace std ;
int main(){
    int n , m ;
    cin >> n >> m ;
    int a[2000000] ;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] ;
    }
    int num[2000000] = {0};
    int t = 0 ;
    for (int i = 0; i < n-m; i++)
    {
        for (int j = i; j < m-1; j++)
        {
            num[i] &= a[i] ;
        }
    }
    int max_ = 0 ;
    for (int i = 0; i < n; i++)
    {
        if (num[i] >= max_)
        {
            max_=num[i] ;
        }
        
    }
    cout << max_ ;
    return 0 ;
}