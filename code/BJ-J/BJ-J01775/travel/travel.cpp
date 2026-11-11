#include <bits/stdc++.h>
using namespace std;
int a1,b1;
int paia,paib;
int ans1,ans2,ans3,ans4;
char gea,geb;
string a2,b2;
int func (string x)
{
    int sum = 0;
    for (int i = 0;i < 3;i++)
    {
        sum = sum * 10 + x[i];
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a1;
    cin >> a2;
    cin >> b1;
    cin >> b2;
    if (a1 == b1)
    {
        ans1 = 1;
    }
    paia = a2[0]*10+a2[1];
    paib = b2[0]*10+b2[1];
    if (paia == paib)
    {
        ans2 = 1;
    }
    gea = a2[2];
    geb = b2[2];
    if (gea <= 'C' && geb <= 'C')
    {
        ans3 = 1;
    }
    if (gea-geb==1 || geb-gea==1)
    {
        ans4 = 1;
    }
    if (ans2 == 0 || ans3 == 0)
    {
        ans4 = 0;
    }
    cout << ans1 << ans2 << ans3 << ans4;
    return 0;