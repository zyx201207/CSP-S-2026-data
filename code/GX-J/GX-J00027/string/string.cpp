#include<bits/stdc++.h>
using namespace std;
const int N = 2000010;
int n, sum = 0;
string s;
int a[N];
char c[N];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int now = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> c[i];
        for(int l = 0; l < a[i]; l++)
        {
            s += c[i];
        }
    }
    //cout << s << "\n";
    int len = s.size();
    for(int i = 0; i < (len / 2); i++)
    {
        if(s[i] != s[len - i - 1])
        {
            sum++;
        }
    }
    printf("%d", sum);
    return 0;
}
