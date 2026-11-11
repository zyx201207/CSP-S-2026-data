#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    long long a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];

    }
    sort(a,a+n);
    long long b=a[n-1];
    for(int i=1;i<m;i++)
    {
        b&=a[n-i-1];
    }
    cout << b;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
