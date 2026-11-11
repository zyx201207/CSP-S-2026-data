#include <bits/stdc++.h>
using namespace std;
long long n,i,m[200005],y;
char s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (i=1;i<=n;i++)
    {
        cin>>m[i]>>s[i];
        y+=m[i];
    }
    int t=1;
    for (i=1;i<n;i++)
    {
        if (s[i]!=s[i+1])
        {
            t=0;
            break;
        }
    }
    if (t)
    {
        cout<<0;
        return 0;
    }
    for (i=n;i>0;i--)
    {
        if (s[i]!=s[i-n+1]&&m[i]!=m[i-n+1])
        {
            if (y%2==0)
            {
                cout<<y/2;
            }
            else
            {
                cout<<(y-1)/2;
            }
            return 0;
        }
    }
    cout<<0;
    return 0;
}
