#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,a[200005],sum,m;
string s2;

string jinzhi(ll a,string s)
{
    while(a>0)
    {
        s += a%2+'0';
        a/=2;
    }
    return s;
}

bool cmp(ll a,ll b)
{
    return a>b;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n,cmp);
   for (int i=2;i<=m;i++)
   {
        string s1;
        s1 = jinzhi(a[i],s1);
        string s2;
        if (i==2)
        {
            s2 = jinzhi(a[1],s2);
        }
        else
        {
            s2 = jinzhi(sum,s2);
            sum=0;
        }
       for (int j=0;j<min(s1.size(),s2.size());j++)
       {
            if (s1[j]=='1' && s2[j]=='1')
           {
                sum += pow(2,j);
            }
        }
    }
    cout << sum;
    return 0;
}
