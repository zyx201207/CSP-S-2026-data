#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in.txt", "r", stdin);
    freopen("string.out.txt", "w", stdout);
    long long n, count = 0;
    string arr;
    cin >> n;
    for(long long i = 0; i < n; i++)
    {
        long long temp1;
        cin >> temp1;
        string temp;
        cin >> temp;
        for(long long j = 0; j < temp1; j++)
            arr += temp;
    }
    for(long long i = 0; i < (arr.length() / 2); i++)
    {
        if(arr[i] != arr[arr.length() - 1 - i])
            count += 1;
    }
    cout << count;
    return 0;
}
