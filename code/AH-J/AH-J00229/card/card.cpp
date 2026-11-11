#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
ll a[500005],t[100005];
void Trya()
{
    for(int i = 1;i <= n;i++)
    {
        if(a[i]!=a[i+1])
        {
            cout << i << " ";
        }
    }
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    bool flagA=1;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i]<a[i-1])
        {
            flagA=0;
            cout << a[i];
        }
    }
    if(flagA)
    {
        Trya();
    }
	return 0;
}
