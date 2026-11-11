#include <iostream>

using namespace std;

const int N = 2e5+10;
int arr[N];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n = 0;
    int m = 0;
    cin >> n >> m;
    int maxn = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxn = max(maxn, arr[i]);
    }
    if (m == 1) cout << maxn << endl;
    maxn = -1;
    if (m == 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                int x = arr[i] & arr[j];
                maxn = max(maxn, x);
            }
        }
        cout << maxn << endl;
    }
    maxn = -1;
    if (m == 3)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    int x = arr[i] & arr[j] & arr[k];
                    maxn = max(maxn, x);
                }
            }
        }
        cout << maxn << endl;
    }
    maxn = -1;
    if (m == 4)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    for (int l = k+1; l < n; l++)
                    {
                        int x = arr[i] & arr[j] & arr[k] & arr[l];
                        maxn = max(maxn, x);
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    maxn = -1;
    if (m == 5)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    for (int l = k+1; l < n; l++)
                    {
                        for (int a = l+1; a < n; a++)
                        {
                            int x = arr[i] & arr[j] & arr[k] & arr[l] & arr[a];
                            maxn = max(maxn, x);
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    maxn = -1;
    if (m == 5)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    for (int l = k+1; l < n; l++)
                    {
                        for (int a = l+1; a < n; a++)
                        {
                            for (int b = a+1; b < n; b++)
                            {
                                int x = arr[i] & arr[j] & arr[k] & arr[l] & arr[a] & arr[b];
                                maxn = max(maxn, x);
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    maxn = -1;
    if (m == 5)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    for (int l = k+1; l < n; l++)
                    {
                        for (int a = l+1; a < n; a++)
                        {
                            for (int b = a+1; b < n; b++)
                            {
                                for (int c = b+1; c < n; c++)
                                {
                                    int x = arr[i] & arr[j] & arr[k] & arr[l] & arr[a] & arr[b] & arr[c];
                                    maxn = max(maxn, x);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    maxn = -1;
    if (m == 5)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    for (int l = k+1; l < n; l++)
                    {
                        for (int a = l+1; a < n; a++)
                        {
                            for (int b = a+1; b < n; b++)
                            {
                                for (int c = b+1; c < n; c++)
                                {
                                    for (int d = c+1; d < n; d++)
                                    {
                                        int x = arr[i] & arr[j] & arr[k] & arr[l] & arr[a] & arr[b] & arr[c] & arr[d];
                                        maxn = max(maxn, x);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    if (m == 20)
    {
        long long abc = arr[0] & arr[1] & arr[2] & arr[3] & arr[4] & arr[5] & arr[6] & arr[7] & arr[8] & arr[9] & arr[10] & arr[11] & arr[12] & arr[13] & arr[14] & arr[15] & arr[16] & arr[17] & arr[18] & arr[19] & arr[20];
        cout << abc << endl;
    }
    return 0;
}
