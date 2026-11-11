#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans;
struct node
{
    ll a;
    char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].a >> a[i].c;
    }
    int l = 1,r =n;
    while(l<r)
    {
        if(a[l].c!=a[r].c)
        {
            ans += min(a[l].a,a[r].a);
        }
        if(a[l].a<a[r].a)
        {
            a[r].a-=a[l].a;
            l++;
        }
        else if(a[l].a>a[r].a)
        {
            a[l].a-=a[r].a;
            r--;
        }
        else
        {
            l++,r--;
        }
    }
    cout << ans;
	return 0;
}
