#include <bits/stdc++.h>
using namespace std;

long long M;
int n;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> M;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (!M) break;
            long long T = max((arr[i] - arr[j]), (arr[j] - arr[i]));

            if (arr[j] > arr[i] && M < T)
            {
                arr[i] += M;
                M = 0;
            }
            else if (arr[j] < arr[i] && M < T)
            {
                arr[j] += M;
                M = 0;
            }
            else if (arr[j] > arr[i] && M >= T)
            {
                M -= T;
                arr[i] += T;
            }
            else if (arr[j] < arr[i] && M >= T)
            {
                arr[j] += T;
                M -= T;
            }
            if (!M) break;
        }
        if (!M) break;
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        int Sum = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j]) Sum++;
        }
        c = max(c, Sum);
    }
    cout << c << endl;
}

