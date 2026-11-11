#include <iostream>

using namespace std;

const int N = 2e5 + 10;
int arr[N];
char ch[N];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n = 0;
    long long cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cin >> ch[i];
    }
    int a = 0;
    int b = n;
    for ( ; a <= b; )
    {
            if (ch[a] == ch[b])
            {
                if (arr[a] > arr[b])
                {
                    arr[a] -= arr[b];
                    b--;
                }
                else if (arr[a] < arr[b])
                {
                    arr[b] -= arr[a];
                    a++;
                }
                else
                {
                    a++;
                    b--;
                }
            }
            else
            {
                if (arr[a] > arr[b])
                {
                    cnt += arr[b];
                    arr[a] -= arr[b];
                    b--;
                }
                else if (arr[a] < arr[b])
                {
                    cnt += arr[a];
                    arr[b] -= arr[a];
                    a++;
                }
                else
                {
                    cnt += arr[a];
                    a++;
                    b--;
                }
            }
    }
    cout << cnt << endl;
    return 0;
}
