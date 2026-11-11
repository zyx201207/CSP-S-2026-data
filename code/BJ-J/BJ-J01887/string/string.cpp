#include <iostream>
using namespace std;
int t(char c)
{
    string s = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0;i < 26;i++)
    {
        if (s[i] == c){return i;}
    }
    return 0;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int N = 20000000;
    int n;cin >> n;int a[n],c[n];char C;int P = 0,p = 0,l[N];
    for (int i = 0;i < N;i++){l[i] = 0;}
    for (int i = 0;i < n;i++)
    {
        cin >> a[i] >> C;c[i] = t(C);P = p;
        for (int j = p;j < p + a[i];j++){l[P] = c[i];P++;}
        p = P;
    }
    int cnt = 0;
    for (int i = 0;i < p;i++)
    {
        if (l[i] != l[L - i - 1]){cnt++;}
    }
    cout << cnt / 2;
    return 0;
}