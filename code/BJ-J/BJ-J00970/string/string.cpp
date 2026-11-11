#include<bits/stdc++.h>
using namespace std;

string S, T;
int n, cnt = 0, L;
int a[20000050];
char c[20000050];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cin >> c[i];
        for (int j = 1; j <= a[i]; j++)
        {
            S += c[i];
        }
        L += a[i];
    }
    for (int i = 0; i < L; i++)
    {
        T[L - i - 1] = S[i];
        //cout << T[L - i - 1] <<'\n';
    }
    //cout << "S : " << S << "T : " << T <<'\n';
    for (int i = 0; i < L; i++)
    {
        if (S[i] == T[i])
        {
            cnt ++;
        }
    }
    cout << (L - cnt) / 2;
    return 0;
}
