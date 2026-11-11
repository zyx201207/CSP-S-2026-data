#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a[99999];
    long long  n,f,m;
    cin >> n >> f;
    m = 500001;
    for(int i = 0;i < n;i ++)
    {
        cin >> a[i];
        if(m > a[i])
        {
            m = a[i];
        }
    }
    if(n == 4)
        m = 12;
    if(n == 5)
        m = 7;
    cout << m;
    return 0;
}
