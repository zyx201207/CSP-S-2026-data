#include<iostream>
using namespace std;
long long a[200010], b[200010];
char c[200010], s[200010];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n;
    cin >> n;
    long long cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    int id = 1;
    long long sum = a[1];
    for(int i = 1; i < n; i++)
    {
        if(c[i] == c[i + 1]) sum += a[i + 1];
        else
        {
            b[id] = sum;
            s[id] = c[i];
            sum = a[i + 1];
            id++;
        }
    }
    if(id == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    int l = 1, r = id;
    while(l < r)
    {
        if(s[l] != s[r]) cnt += (abs(b[l] - b[r]) + min(b[l], b[r]));
        else if(b[l] != b[r]) cnt += abs(b[l] - b[r]);
        l++;
        r--;
    }
    cout << cnt << endl;
    return 0;
}
