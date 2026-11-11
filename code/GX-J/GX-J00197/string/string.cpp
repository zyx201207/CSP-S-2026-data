#include<bits/stdc++.h>
using namespace std;
int n;
int a;
string c;
string s;
int sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a >> c;
        for (int j=1;j<=a;j++)
            s = s + c;
    }
    for (int i=0,j=s.size()-1;i<=j;i++,j--)
    {
        if (s[i] != s[j])
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
