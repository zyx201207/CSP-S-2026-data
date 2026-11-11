#include <bits/stdc++.h>

using namespace std;

long long a[200005];
char c[200005];
long long s = 0;
int n;
long long sum = 0;

int main()
{
    
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i] >> c[i];
    }
    string b;
    for(int i = 0;i < n;i++)
    {
        for(int j = s;j < s + a[i];j++)
        {
            b += c[i];
        }
        s += a[i];
    }
    int l = 0,r = s - 1;
    for(int i = 0;i < s / 2;i++)
    {
        if(b[l] != b[r])
        {
            sum++;
        }
        l++;
        r--;
    }
    cout << sum;

    return 0;
}

